#include "GameState.hpp"
/* This class inherits from GameState */

class FiveLetterWordScramble_State: public GameState {
private:
  //
public:
  int getCurrentTick() override;
  void setCurrentTick(int n) override;
};
