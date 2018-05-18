#include "GameEngine.hpp"
#include "FiveLetterWordScramble_Mode.hpp"
#include "main.hpp"
#include <iostream>
#include <stdio.h>

int main(){
  int c;
  while(1){
    std::cout << "Press any key to start game: Five-Letter Word Scramble" << std::endl;
    std::cout << "or press 'q' to Quit" << std::endl;
    c = getchar();
    if(getchar() != '\n') return 1; // Expecting 1 char and \n
    if (c == 'q') {
      return 0;
    } else {
      GameEngine *FinalP205 = new GameEngine(new FiveLetterWordScramble_Mode);
      FinalP205->setUp();
    }
    c = 0;
  }
  return 0;
}
