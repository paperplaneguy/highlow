#include "HighLow.hpp" //for llimit and ulimit
#include <cstdint>     //for int8_t
#include <string>      //for stoi()
#include <cstring>     //for strcmp()
#include <iostream>    //for cerr and endl
#include <vector>      //for std::vector
#include <string>      //for std::string

using std::stoi;
using std::string;
using std::vector;
using options::llimit;
using options::ulimit;

//The following function sets arguments, and returns false if fails
bool setArguments(vector<string> args);

int main(int argc, char **argv) {
  if(argc > 1)
    if(!setArguments(vector<string>(argv + 1, argv + argc)))
      return 0;
  HighLow::game();
  return 0;
}

bool setArguments(vector<string> arg_v) {
  /* if any argument is passed to the game it will check if the user wants  *
   * to change the amount of guesses per number or the upper and lower      *
   * limit of the random number generated. Other arguments are totally      *
   * ignored.                                                               */
  for (size_t i(0); i < arg_v.size(); i++) {
    if((arg_v[i] == "-g") || (arg_v[i] == "--guesses"))
      options::totalguesses = stoi(arg_v[++i]);
    else 
      if ((arg_v[i] == "-l") || (arg_v[i] == "--llimit"))
        llimit = stoi(arg_v[++i]);
        else
          if ((arg_v[i] == "-u") || (arg_v[i] == "--ulimit"))
            ulimit = stoi(arg_v[++i]);
          else {
            std::cerr << "Invalid argument " << arg_v[i] << std::endl;
            return false;
          }
  }
  return true;
}