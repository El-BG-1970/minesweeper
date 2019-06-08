#include <cstring>
#include <iostream>


void help_msg()
{
    using namespace std;     

    cout << "minesweeper, version 1.0.0-beta" << endl << endl<<
        "usage: minesweeper [-w width] [-h height] [-m mines] [--help]" << endl << endl <<
        "Options:" << endl <<
        "--help :\t Print this help message." << endl <<
        "-w :\t Change the grid's width." << endl <<
        "-h :\t Change the height of the grid." << endl <<
        "-m :\t Change the number of mines on the grid." << endl << endl <<
        "To play, input the coordinates of the position you want to test, putting the row first and the column second." << endl;

}
