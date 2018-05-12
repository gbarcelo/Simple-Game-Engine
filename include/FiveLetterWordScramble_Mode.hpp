#include "GameMode.hpp"
#include "FiveLetterWordScramble_State.hpp"
#include <vector>
#include <string>

/* This class inherits from GameMode */

class FiveLetterWordScramble_Mode: public GameMode {
private:
  FiveLetterWordScramble_State *state;
  std::vector<std::string> dictionary;
  std::vector<std::string> validAnswers;
  // Builds dictionary of words for game mode
  void loadDictionaryFromFile();
  // Returns a random word from the dictionary (five letter?)
  std::string randomWordSelector();
  // Gets all valid permutations of s in the dictionary
  void setValidAnswers(std::string s);

public:
  FiveLetterWordScramble_Mode();

  TickType getTickType() const override;
  // void setTickType(TickType t) override {tick = t;}

  void setUp() override;

  void updatePerTick() override;

  bool isEndGame() override;

  void endSession() override;


};
