#include "stdio.h"
#include "cstdlib"
#include "./grid.hpp"

// class definition
class Game {
public:
  Game();
  bool isrunning();
  void show_board();
  void reveal(int, int);

private:
  bool s_running;
  Grid *grid;
};
