#include "./game.hpp"

// func definitions
Game::Game(int w, int h, int m){
    s_running = true;
    grid = new Grid(w, h, m);
    grid->init_mines();
}

void Game::show_board(){
  grid->print();
}

void Game::show_all(){
  grid->reveal_all();
  grid->print();
}

bool Game::isrunning(){
    return(s_running);
}

void Game::reveal(int x, int y) {
  if(!grid->reveal(x, y)){
    grid->print();
    printf("\n\nGAME OVER!\n");
    s_running = false;
  }
}

bool Game::won(){
  return(grid->win());
}
