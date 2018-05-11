#include "GameEngine.hpp"
#include "FiveLetterWordScramble_Mode.hpp"
#include "main.hpp"
#include <iostream>
#include <stdio.h>

int main(){
  while(1){
    int c;
    std::cout << "Press any key to start game: Five-Letter Word Scramble" << std::endl;
    std::cout << "or press 'q' to Quit" << std::endl;
    c = getchar();
    if (c == 'q') {
      return 0;
    } else {
      GameEngine(new FiveLetterWordScramble_Mode);
    }
  }
  return 0;
}
