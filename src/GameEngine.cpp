#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine(GameMode game_) :
    game(game_) {
    tick = game_.
  }

void GameEngine::setUp(){
  //

  // SetUp Complete, begin main game loop
  if (game.TickType == Rounds){
    GameEngine::mainLoop_Rounds();
  } else {
    std::cout << "Error: Game TickType: Not yet implemented" << std::endl;
  }
}

void GameEngine::mainLoop_Rounds(){
  //

}

void GameEngine::sessionSummary(){
  //
}