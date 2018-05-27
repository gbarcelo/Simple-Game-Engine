#include "GameState.hpp"
#include <vector>
#include <string>
/* This class inherits from GameState */

#define END_PT    20
#define END_MULT  5
#define PTS_5L    6
#define PTS_4L    4
#define PTS_3L    2

class FiveLetterWordScramble_State: public GameState {
private:
  std::string currWord; // Current word for word scramble
  std::vector<std::string> validGuesses; // User's valid guesses
  int numWrongAnswers = 0;
  int score = 0;

public:
  FiveLetterWordScramble_State();

  std::string getCurrWord() const;
  void setCurrWord(std::string s);

  std::vector<std::string> getValidGuesses() const;
  void pushValidGuess(std::string s);

  int getNumWrong() const;
  void incrementNumWrong();

  int getScore() const;
  void incrementScore(int n);

  int getCurrentTick() override;
  void setCurrentTick(int n) override;
  void incrementTick();

};
