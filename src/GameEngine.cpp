#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine(GameMode *game_){
  game = game_;
  game_ = NULL;
  tick = game->getTickType();
}

void GameEngine::setUp(){
  // Interface method that sets up resources for game
  game->setUp();

  // SetUp Complete, begin main game loop

  if (tick == TickType::Rounds){
    mainLoop_Rounds();
  } else if (tick == TickType::Turns){
    mainLoop_Turns();
  } else {
    std::cout << "Error: Game TickType: Not yet implemented" << std::endl;
  }
}

void GameEngine::mainLoop_Rounds(){
  // Interface method that returns true if game has ended
  while(!game->isEndGame()){
    // Interface method that updates game state
    game->updatePerTick();
  }
  sessionSummary();
}

void GameEngine::mainLoop_Turns(){
  // Interface method that returns true if game has ended
  while(!game->isEndGame()){
    // Interface method that updates game state
    game->updatePerTick();
  }
  sessionSummary();
}

void GameEngine::sessionSummary(){
  // Interface method that runs after game is Complete
  game->endSession();
}
