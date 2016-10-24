#include <iostream>
#include "HighLow.hpp"
#include <random>
#include <fstream>
#include <string>
#include <cstdio>

const string tab("\t");

namespace options {
  int8_t llimit(0), ulimit(100), totalguesses(7), startlevel(0), startscore(0), startguess(1);
}

namespace HighLow {
  using std::to_string;
  using std::endl;
  using std::cout;
  using std::string;
  using std::stoi;
  using std::ifstream;
  using std::cin;

  using options::totalguesses;
  using options::ulimit;
  using options::startlevel;
  using options::startscore;
  using options::startguess;

  int8_t level(startlevel), score(options::startscore); //Level count and current score
  string savefile("saved.hl");

  string levelStatus() {
    ++level;
    if (level==1)
      return "Level 1:"+tab+tab+"Score: -";
    else
      return "Level " + to_string(level) + ":" + tab + tab + "Score: " + to_string(score);
  }

  int8_t randomNumber() {
    std::random_device rd; std::mt19937 random(rd());
    return (static_cast<int>(random() % (ulimit + 1)) + (options::llimit + 1));
  }

  void getGuesses(int8_t number) {
    for(int guess(options::startguess); guess <= totalguesses; guess++){
      cout << "Guess " << guess << ": "; string input; std::getline(std::cin, input);
      if(input == "save" || input == "SAVE") save(guess);
      if(isnumber(input)) {
        if(stoi(input) == number) {score++; cout << "Correct!" << endl << endl; return;}
          else if (stoi(input) < number)  {cout << "Too Low" << endl << endl; continue;}
            else {cout << "Too High" << endl << endl; continue;}
        }
    }
    score -= 2; //decrement two points if the user isn't successfull
  }

  void game() {
    if (isresumed()) resume();
    else
      cout << "I am thinking of a number, you have " << static_cast<int>(totalguesses) << " times to guess what it is." << endl;
    do {
      cout << levelStatus() << endl;
      getGuesses(randomNumber());
    } while(score > 0);
    cout << endl << "You had reached level " << static_cast<int>(level) << ". Nice try! All the best for the next time." << endl;
    deletesaved();
  }

  void save(int8_t guess) {
    std::ofstream save(savefile, std::ios::trunc);
    save << --level << score << guess << ulimit << totalguesses;
    save.close(); exit(0);
  }

  void resume() {
    ifstream file(savefile);
    file >> startlevel >> startscore >> startguess >> ulimit >> totalguesses;
    file.close();
  }

  void deletesaved() { remove(savefile.c_str()); }

  bool isnumber(string input) { return (input.find_first_not_of("0123456789") == string::npos); }

  bool isresumed() { ifstream file(savefile); return file.good(); }
}
