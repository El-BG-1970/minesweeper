#include "stdio.h"
#include "cstdlib"
#include "./game.hpp"
#include "./get_input.hpp"
#include "./help.hpp"

using namespace std;

int main(int argc, char **argv)
{
  int *parameters;
  parameters = (int *)malloc(3*sizeof(int));

  if (argv[1] && (!strcmp(argv[1], "--help"))){
    help_msg();  
    return(0);
  }

  parameters = get_input(argc, argv);

  if (parameters[2] > (parameters[0] * parameters[1])/2 ){
      printf("Too many mines!! \n");
      return(-1);
  }

  Game game(parameters[0], parameters[1], parameters[2]);
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
    game.reveal(x[0], y[0]);
  }

  if (game.won()){
    printf("\n\n");
    game.show_all();
    printf("\n\nYOU WON\n");
  }
  return (0);
}
