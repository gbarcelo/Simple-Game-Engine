#include "GameState.hpp"
#include <string>
/* This class inherits from GameState */

class FiveLetterWordScramble_State: public GameState {
private:
  std::string currWord; // Current word for word scramble
public:
  FiveLetterWordScramble_State();
  int getCurrentTick() override;
  void setCurrentTick(int n) override;
  void incrementTick();

};
