#include "GameState.hpp"

/*  This is an abstract class
 *  Consider adding 3- and 4- letter words for
 *  lower score values
*/

// Time-tracking mechanic
enum class TickType { Real_Time, Custom_Tick, Rounds, Turns };

class GameMode{
private:
  enum TickType tick;
  GameState state;

public:

}
