#ifndef HIGHLOW_HPP
#define HIGHLOW_HPP

#include <string> //for std::string
#include <cstdint> //for int8_t

using std::string;

namespace options {
  extern int8_t lower_limit, upper_limit, total_guesses, start_level, start_guess, start_score;
}

/* lower_limit:       lower limit of the random number                             *
 * upper_limit:       upper limit of the random number                             *
 * total_guesses: the number of times the user is allowed to guess             *
 * start_level:   to set the starting level of the game (if it is resumed)     *
 * start_guess:   to set the guess number to start from (if it is resumed)     *
 * start_score:   the score to start the game with (in case it is resumed)     */

namespace HighLow{
  extern int8_t level, score; //stores the level count and score
  extern string save_file; //stores the location of the file in which scores are saved
  string levelStatus(); //Shows the level number and score;
  int8_t randomNumber(); //Produces random numbers
  void getGuesses(int8_t number); //Asks the user for numbers and produces result. Takes a random number;
  void game(); //the layer between user and program;
  void save(int8_t guess); //to save game state
  void resume(); //to resume the game
  void deleteSaved(); //to delete the saved state
  bool isNumber(string); //to check if the string represents a number
  bool isResumed(); //to check if the game is resumed
}

#endif
