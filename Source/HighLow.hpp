#ifndef HIGHLOW_HPP
#define HIGHLOW_HPP

#include <string> //for std::string
#include <cstdint> //for int8_t

using std::string;

namespace options {
  extern int8_t llimit, ulimit, totalguesses, startlevel, startguess, startscore;
}

namespace HighLow{
  extern int8_t level, score;
  extern string savefile;
  string levelStatus(); //Shows the level number and score;
  int8_t randomNumber(); //Produces random numbers
  void getGuesses(int8_t number); //Asks the user for numbers and produces result. Takes a random number;
  void game(); //the layer between user and program;
  void save(int8_t guess); //to save game state
  void resume(); //to resume the game
  void deletesaved(); //to delete the saved state
  bool isnumber(string); //to check if the string represents a number
  bool isresumed(); //to check if the game is resumed
}

#endif
