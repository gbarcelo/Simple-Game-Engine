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
  void mainLoop();

  // Anything needed after a game ends goes here
  void sessionSummary();
}
