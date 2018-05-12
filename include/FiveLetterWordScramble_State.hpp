#include "GameState.hpp"
/* This class inherits from GameState */

class FiveLetterWordScramble_State: public GameState {
private:
  //
public:
  FiveLetterWordScramble_State();
  int getCurrentTick() override;
  void setCurrentTick(int n) override;
  void incrementTick();

};
