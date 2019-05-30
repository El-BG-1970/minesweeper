#include "cstdio"
#include "cstdlib"

class Grid {
public:
    Grid(int, int);
    bool exists(int, int);
    bool is_revealed(int, int);
    void init_mines();
    void print();
    void reveal(int, int);

private:
    int s_h; // height
    int s_w; // width
    int **board;
    bool **revealed;
};
