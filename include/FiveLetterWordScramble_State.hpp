#include "GameState.hpp"
#include <string>
/* This class inherits from GameState */

class FiveLetterWordScramble_State: public GameState {
private:
  std::string currWord; // Current word for word scramble
  std::vector<std::string> validGuesses; // User's valid guesses
  int numWrongAnswers = 0;

public:
  FiveLetterWordScramble_State();

  std::string getCurrWord() const;
  void setCurrWord(std::string s);

  std::vector<std::string> getValidGuesses() const;
  void pushValidGuess(std::string s);

  int getNumWrong() const;
  void incrementNumWrong();

  int getCurrentTick() override;
  void setCurrentTick(int n) override;
  void incrementTick();

};
