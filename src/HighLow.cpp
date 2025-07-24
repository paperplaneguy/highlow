// notes:
// • consts are used instead of #defines for namespacing

#include <iostream>
#include "HighLow.hpp"
#include <random>
#include <fstream>
#include <string>
#include <cstdio>

const string tab("\t");

namespace options {
  int8_t lower_limit  (0)  ,
         upper_limit  (100),
         total_guesses(7)  , 
         start_level  (0)  ,
         start_score  (0)  ,
         start_guess  (1)  ;
}

namespace HighLow {
  using std::to_string;
  using std::endl;
  using std::cout;
  using std::string;
  using std::stoi;
  using std::ifstream;
  using std::cin;

  using options::total_guesses;
  using options::upper_limit;
  using options::start_level;
  using options::start_score;
  using options::start_guess;

  //setting the level count and current score
  int8_t level(start_level), score(options::start_score);
  const string save_file("saved.hl"); //the save_file location

  string levelStatus() {
    ++level;
    if (level == 1)
      return "Level 1:" + tab + tab + "Score: -";
    else
      return "Level " + to_string(level) + ":" + tab + tab + "Score: " + to_string(score);
  }

  int8_t randomNumber() {
    std::random_device rd; std::mt19937 random(rd());
    return ( static_cast<int>(random() % (upper_limit + 1)) + (options::lower_limit + 1) );
  }

  void getGuesses(int8_t number) {
    for(int guess(options::start_guess); guess <= total_guesses; guess++){
      cout << "Guess " << guess << ": "; string input; std::getline(std::cin, input);
      if(input == "save" || input == "SAVE") save(guess);
      if(isNumber(input)) {
        if(stoi(input) == number) {score++; cout << "Correct!" << endl << endl; return;}
          else if (stoi(input) < number)  {cout << "Too Low" << endl << endl; continue;}
            else {cout << "Too High" << endl << endl; continue;}
        }
    }
    score -= 2; //decrement two points if the user isn't successfull
  }

  void game() {
    if (isResumed()) resume();
    else
      cout << "I am thinking of a number, you have " << static_cast<int>(total_guesses)
           << " times to guess what it is." << endl;
    do {
      cout << levelStatus() << endl;
      getGuesses(randomNumber());
    } while(score > 0);
    cout << endl << "You had reached level " << static_cast<int>(level)
         << ". Nice try! All the best for the next time." << endl;
    deleteSaved();
  }

  void save(int8_t guess) {
    std::ofstream save(save_file, std::ios::trunc);
    save << --level << score << guess << upper_limit << total_guesses;
    save.close(); exit(0);
  }

  void resume() {
    ifstream file(save_file);
    file >> start_level >> start_score >> start_guess >> upper_limit >> total_guesses;
    file.close();
  }

  void deleteSaved() { remove(save_file.c_str()); }

  bool isNumber(string input) { return (input.find_first_not_of("0123456789") == string::npos); }

  bool isResumed() { ifstream file(save_file); return file.good(); }
}
