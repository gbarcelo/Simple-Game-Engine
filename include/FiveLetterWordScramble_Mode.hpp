#include "GameMode.hpp"
#include "FiveLetterWordScramble_State.hpp"
/* This class inherits from GameMode */

class FiveLetterWordScramble_Mode: public GameMode {
private:
  //
public:
  FiveLetterWordScramble_Mode();

  TickType getTickType() const override;
  // void setTickType(TickType t) override {tick = t;}

  void setUp() override;

  void updatePerTick() override;

  bool isEndGame() override;

  void endSession() override;

};
