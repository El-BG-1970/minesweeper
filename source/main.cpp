#include "stdio.h"
#include "cstdlib"
#include "./game.hpp"

using namespace std;

int main()
{
  Game game;
  int *x;
  int *y;

  x = (int *)malloc(sizeof(int));
  y = (int *)malloc(sizeof(int));

  x[0] = 0;
  y[0] = 0;

  while (game.isrunning() && !game.won()){
    printf("\n\n current state: \n");
    game.show_board();

    printf("your move: \n");
    scanf("%i %i", x, y);
    //printf("%i %i \n", x[0], y[0]);
    game.reveal(x[0], y[0]);
  }

  if (game.won()){
    game.show_all();
    printf("\n\n\nYOU WON\n");
  }
  return (0);
}
