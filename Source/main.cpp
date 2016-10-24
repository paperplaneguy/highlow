#include "HighLow.hpp"
#include <cstdint>
#include <string>
#include <cstring>
#include <cassert>

using std::stoi;
using options::llimit; using options::ulimit;


int main(int argc, char *argv[]) {
  if(argc > 0) {
    for(int i(1); i < argc; i++) {
      if( !(strcmp(argv[i], "-g") && strcmp(argv[i], "--guesses")) )
        options::totalguesses = stoi(argv[i+1]);
      else if( !(strcmp(argv[i], "-l") && strcmp(argv[i], "--llimit")) )
        llimit = stoi(argv[i+1]);
      else if( !(strcmp(argv[i], "-u") && strcmp(argv[i], "--ulimit")) )
        ulimit = stoi(argv[i+1]);
    }
    assert(llimit < ulimit);
  }
  HighLow::game(); return 0;
}
