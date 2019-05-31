#include "./game.hpp"

// func definitions
Game::Game(){
    s_running = true;
    grid = new Grid(10, 10, 10 );
    grid->init_mines();
}

void Game::show_board(){
    grid->reveal_all();
    grid->print();
}

bool Game::isrunning(){
    return(s_running);
}

void Game::reveal(int x, int y) {
  grid->reveal(x,y);
}
