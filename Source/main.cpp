#include "HighLow.hpp" //for llimit and ulimit
#include <cstdint>     //for int8_t
#include <string>      //for stoi()
#include <cstring>     //for strcmp()
#include <iostream>    //for cerr and endl

using std::stoi;
using options::llimit; using options::ulimit;


int main(int argc, char *argv[]) {
  if(argc > 0) {
    /* if any argument is passed to the game it will check if the user wants  *
     * to change the amount of guesses per number or the upper and lower      *
     * limit of the random number generated. Other arguments are totally      *
     * ignored.                                                               */
    for(int i(1); i < argc; i++) {
      if( !(strcmp(argv[i], "-g") && strcmp(argv[i], "--guesses")) )
        options::totalguesses = stoi(argv[i+1]);
      else if( !(strcmp(argv[i], "-l") && strcmp(argv[i], "--llimit")) )
        llimit = stoi(argv[i+1]);
        else if( !(strcmp(argv[i], "-u") && strcmp(argv[i], "--ulimit")) )
          ulimit = stoi(argv[i+1]);
          else {
            std::cout << "Imvalid Argument " << argv[i] << std::endl;
            return -1;
          }
    }
    if(llimit > ulimit) {
      std::cerr << "Invalid limits. Eixiting." << std::endl;
      return -1;
    }
  }
  HighLow::game(); return 0;
}
