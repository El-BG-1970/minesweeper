#include "cstdio"
#include "cstdlib"

class Grid {
public:
  Grid(int, int, int);
  bool exists(int, int);
  bool ismine(int, int);
  void init_mines();
  void print();
  bool reveal(int, int);
  void reveal_all();
  int adjascent_mines(int, int);
  bool win();

private:
  int s_h; // height
  int s_w; // width
  int mines;
  int **board;
  bool **revealed;
  int left;
  bool large;
};
