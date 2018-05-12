#include "GameMode.hpp"
#include "FiveLetterWordScramble_State.hpp"
#include <vector>
#include <string>

/* This class inherits from GameMode */

class FiveLetterWordScramble_Mode: public GameMode {
private:
  FiveLetterWordScramble_State *state;
  std::vector<std::string> dictionary;
  // Builds dictionary of words for game mode
  void loadDictionaryFromFile();
  
public:
  FiveLetterWordScramble_Mode();

  TickType getTickType() const override;
  // void setTickType(TickType t) override {tick = t;}

  void setUp() override;

  void updatePerTick() override;

  bool isEndGame() override;

  void endSession() override;


};
