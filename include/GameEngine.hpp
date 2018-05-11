#include "GameMode.hpp"
#include "GameState.hpp"

// Time-tracking mechanic
enum class TickType { Real_Time, Custom_Tick, Rounds, Turns };

class GameEngine{
private:
  enum TickType tick;
  GameMode game;
  GameState gameState;
  bool isEndGame;

public:
  GameEngine(GameMode game_, GameState gameState_);

  // Anything needed before MainLoop starts goes here
  void setUp();

  // MainLoop where GameState is continuously updated until end of game
  // TickType: Rounds
  void mainLoop_Rounds();
  // Other TickTypes not implemented yet
  void mainLoop_Real_Time();
  void mainLoop_Custom_Tick();
  void mainLoop_Turns();

  // Anything needed after a game ends goes here
  void sessionSummary();
}
