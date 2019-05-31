#include "stdio.h"
#include "cstdlib"
#include "./grid.hpp"

// class definition
class Game {
public:
  Game();
  bool isrunning();
  bool won();
  void show_board();
  void show_all();
  void reveal(int, int);

private:
  bool s_running;
  Grid *grid;
};
