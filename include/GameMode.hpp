#ifndef GAMEMODE_HPP
#define GAMEMODE_HPP
#include "GameState.hpp"

/*  This is an abstract class
 *  Consider adding 3- and 4- letter words for
 *  lower score values
*/

// Time-tracking mechanic
enum class TickType { Real_Time, Custom_Tick, Rounds, Turns };

class GameMode{
protected:
  TickType tick;
  //GameState *state; // Need to create mode-unique state class

public:
  virtual TickType getTickType() const = 0;
  // virtual void setTickType() = 0;

  // Interface method that sets up resources for game
  virtual void setUp() = 0;

  // Interface method that updates game state
  virtual void updatePerTick() = 0;

  // Interface method that returns true if game has ended
  virtual bool isEndGame() = 0;

  // Interface method that runs after game is Complete
  virtual void endSession() = 0;
};

#endif
