#include "cstdio"
#include "cstdlib"

class Grid {
public:
  Grid(int, int, int);
  bool exists(int, int);
  bool is_revealed(int, int);
  bool ismine(int, int);
  void init_mines();
  void print();
  void reveal(int, int);
  void reveal_all();

private:
  int s_h; // height
  int s_w; // width
  int mines;
  int **board;
  bool **revealed;
};
