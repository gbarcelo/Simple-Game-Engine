#include "FiveLetterWordScramble_State.hpp"
/* This class inherits from GameState */

FiveLetterWordScramble_State::FiveLetterWordScramble_State() { }

std::string FiveLetterWordScramble_State::getCurrWord() const {return currWord;}
void FiveLetterWordScramble_State::setCurrWord(std::string s) {currWord = s;}
int FiveLetterWordScramble_State::getCurrentTick() {return currentTick;}
void FiveLetterWordScramble_State::setCurrentTick(int n) {currentTick = n;}
void FiveLetterWordScramble_State::incrementTick() {currentTick++;}
