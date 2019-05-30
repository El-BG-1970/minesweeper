#include "./grid.hpp"

Grid::Grid(int w, int h) {
  s_w = w + 1;
  s_h = h + 1;

  int i = 1;
  int j = 1;

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

  for (i = 1; i < s_w; i++) {
    for (j = 1; j < s_h; j++) {
      board[i][j] = 0;
      revealed[i][j] = false;
    }
  }
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
          if (j == s_h - 1)
            printf("%i \n", board[i][j]);
          else
            printf("%i, ", board[i][j]);
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

bool Grid::is_revealed(int x, int y){
    if(exists(x,y))
        return(revealed[x][y]);
    else{
        printf("(%i ; %i) doesn't exist...\n", x, y);
        return(false);
    }
}

void Grid::reveal(int x, int y) {
  if (this->exists(x, y) && !revealed[x][y]){
    revealed[x][y] = true;
  }
  if (this->exists(x,y) && revealed[x][y])
    printf("(%i ; %i) already revealed...\n", x, y);
  else
    printf("(%i ; %i) doesn't exist...\n", x, y);
}
