#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
/* This is an abstract class
 *  - may need to separate into GameState
 *    and PlayerState
*/

class GameState{
protected:
  int currentTick;
  // vector of <players>?
public:
  // Abstraction to force implementation of mode-specific state
  virtual int getCurrentTick() = 0;
  virtual void setCurrentTick(int n) = 0;
};

#endif
