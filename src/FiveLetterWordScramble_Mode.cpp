#include "FiveLetterWordScramble_Mode.hpp"
#include <fstream>
#include <sstream>
#include <utility>
// #include <algorithm>
// temporary include DEBUG
#include <iostream>
/* This class inherits from GameMode */

FiveLetterWordScramble_Mode::FiveLetterWordScramble_Mode() {
  tick = TickType::Rounds;
  // FiveLetterWordScramble_State *s = new FiveLetterWordScramble_State();
  // state = dynamic_cast<GameState*>(s);
  // state = std::move(s);
  state = new FiveLetterWordScramble_State();
}

// Build data member "dictionary" from a file "dictoinary.db"
void FiveLetterWordScramble_Mode::loadDictionaryFromFile(){
  std::ifstream infile("data/dictionary.db");
  std::string line;
  while(std::getline(infile, line)){
    // std::cout << line << std::endl;
    int i = 0;
    int flag = 0;
    for(int i = 0; line[i]!='\0';++i){
      if(!(line[i]>='a'&& line[i]<='z')){
        flag = 1;
        break;
      }
    }
    if (!flag){ dictionary.push_back(line); }
  }

  // DEBUG
  std::cout << "Dictionary Built: ";
  std::cout << "Size = " << dictionary.size() << std::endl;

}

/****************************
 * Interface Override Methods:
 ****************************/
TickType FiveLetterWordScramble_Mode::getTickType() const {return tick;}
// void setTickType(TickType t) override {tick = t;}

void FiveLetterWordScramble_Mode::setUp() {
  loadDictionaryFromFile();
}

void FiveLetterWordScramble_Mode::updatePerTick() {
  //
  state->incrementTick();
}

bool FiveLetterWordScramble_Mode::isEndGame() {
  if (state->getCurrentTick() > 100000000) {
    return 1;
  }
  return 0;
}

void FiveLetterWordScramble_Mode::endSession() {
  //
}
