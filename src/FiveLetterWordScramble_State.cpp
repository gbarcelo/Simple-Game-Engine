#include "FiveLetterWordScramble_State.hpp"
/* This class inherits from GameState */

FiveLetterWordScramble_State::FiveLetterWordScramble_State() { }

std::string FiveLetterWordScramble_State::getCurrWord() const {return currWord;}
void FiveLetterWordScramble_State::setCurrWord(std::string s) {currWord = s;}

std::vector<std::string> FiveLetterWordScramble_State::getValidGuesses() const {return validGuesses;}
void FiveLetterWordScramble_State::pushValidGuess(std::string s) {validGuesses.push_back(s);}

int FiveLetterWordScramble_State::getNumWrong() const {return numWrongAnswers;}
void FiveLetterWordScramble_State::incrementNumWrong() {numWrongAnswers++;}

int FiveLetterWordScramble_State::getScore() const {return score;}
void FiveLetterWordScramble_State::incrementScore(int n){
  switch(n){
    case 42:
    score+=END_PT;
    break;

    case 5:
    score+=PTS_5L;
    break;

    case 4:
    score+=PTS_4L;
    break;

    case 3:
    score+=PTS_3L;
    break;
  }
}

int FiveLetterWordScramble_State::getCurrentTick() {return currentTick;}
void FiveLetterWordScramble_State::setCurrentTick(int n) {currentTick = n;}
void FiveLetterWordScramble_State::incrementTick() {currentTick++;}
