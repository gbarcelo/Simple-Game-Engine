# Simple Game Engine with Interface
A simple game engine that implements new games using a GameMode abstract class and an optional GameState abstract class. Currently runs in terminal only (no graphics), but SFML is being considered. Good practice for beginner C++ programming.

## Current Games:
 - Five-Letter Word Scramble
 
## Interface:
 To add a game to the engine:
 - inherit from GameMode and GameState abstract classes as needed
 - add game to main menu
 
 Note: Only one type of game-tick is currently available and will be implemented as needed.
 
## Compile instructions
Use `make run` to compile code and run automatically. Executable is placed in `bin/`.
