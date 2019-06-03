#include "./grid.hpp"
#include "time.h"

Grid::Grid(int w, int h, int num_of_mines) {
  s_w = w + 1;
  s_h = h + 1;
  mines = num_of_mines;
  left = h*w;

  int i = 1;
  
  board = (int **)malloc(s_w * sizeof(int *));
  revealed = (bool **)malloc(s_w * sizeof(bool *));

  for (i = 1; i < s_w; i++) {
    board[i] = (int *)malloc(s_h * sizeof(int));
    revealed[i] = (bool *)malloc(s_h * sizeof(bool));
  }
}

void Grid::init_mines() {
  int i = 1;
  int j = 1;
  int k = 1;
  srand(time(NULL));

  // fill board
  for (i = 1; i < s_w; i++) {
    for (j = 1; j < s_h; j++) {
       board[i][j] = 0;
      revealed[i][j] = false;
    }
  }

  // add mines
  for (k = 1; k <= mines;)
  {
    int x = rand() % s_w;

    int y = rand() % s_h;

    if (exists(x, y) && (board[x][y] != -1)) {
      board[x][y] = -1;
      k++;
    }
  }
}

int Grid::adjascent_mines(int x, int y){
    int count;
    int i, j;
    i = x-1;
    j = y-1;
    count = 0;

    for (i = x-1; i<=x+1; i++){
      for (j = y-1; j<=y+1; j++){
        if (!((i == x) && (j == y))){
          if (exists(i,j) && board[i][j] == -1)
            count++;
            }
        }
    }
    return(count);
}

void Grid::print() {
  int i = 1;
  int j = 0;

  for (i = 0; i < s_w; i++) {
    for (j = 0; j < s_h; j++) {
      if (i == 0) { /* print coordinates */
        if (j == 0)
          printf("%i \t", j);
        else {
          printf("%i  ", j);
          if (j == s_h - 1)
            printf("\n\n\n");
        }
      }
      if (j == 0 && i != 0)
        printf("%i \t", i);

      if (j > 0 && i > 0) {
        if (!revealed[i][j]) {
          if (j == s_h - 1)
            printf("- \n");
          else
            printf("-, ");
        } else {
          if (board[i][j] != -1) {
            if (j == s_h - 1)
              //printf("%i \n", board[i][j]);
              printf("%i \n", adjascent_mines(i,j));
            else
              //printf("%i, ", board[i][j]);
              printf("%i, ", adjascent_mines(i,j));
          } else {
            if (j == s_h - 1)
              printf("X \n");
            else
              printf("X, ");
          }
        }
      }
    }
  }
}

bool Grid::exists(int x, int y) {
  if (x < s_w && x > 0 && y < s_h && y > 0)
    return (true);
  else
    return (false);
}

bool Grid::ismine(int x, int y){
  if (exists(x, y) && (board[x][y] == -1))
      return(true);
  else
      return(false);
}

bool Grid::reveal(int x, int y) {
  if (exists(x,y) && (board[x][y] == -1)){
    reveal_all();
    return(false);
  }
  if (exists(x, y) && !revealed[x][y]){
    revealed[x][y] = true;

    if(adjascent_mines(x,y) == 0){
      for (int i = x-1; i<=x+1; i++){
        for (int j = y-1; j<=y+1; j++){
          if(exists(i,j) && !revealed[i][j])
            reveal(i,j);
        }
      }
    }
    left -= 1;
    return(true);
  }
  if (exists(x,y) && revealed[x][y])
    printf("(%i ; %i) already revealed...\n", x, y);
  else
    printf("(%i ; %i) doesn't exist...\n", x, y);
  return(true);
}

void Grid::reveal_all() {
  int i = 1;
  int j = 1;

  // fill board
  for (i = 1; i < s_w; i++) {
    for (j = 1; j < s_h; j++)
      revealed[i][j] = true;
  }
}

bool Grid::win(){
  if (left == mines)
    return(true);
  else
    return(false);
}
