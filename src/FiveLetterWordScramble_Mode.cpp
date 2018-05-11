#include "FiveLetterWordScramble_Mode.hpp"
/* This class inherits from GameMode */

FiveLetterWordScramble_Mode::FiveLetterWordScramble_Mode(){

}

TickType FiveLetterWordScramble_Mode::getTickType() const {return tick;}
// void setTickType(TickType t) override {tick = t;}

void FiveLetterWordScramble_Mode::setUp() {
  //
}

void FiveLetterWordScramble_Mode::updatePerTick() {
  //
}

bool FiveLetterWordScramble_Mode::isEndGame() {
  //
  return 0;
}

void FiveLetterWordScramble_Mode::endSession() {
  //
}
