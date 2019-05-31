#include "./game.hpp"

// func definitions
Game::Game(){
    s_running = true;
    grid = new Grid(10, 10, 10 );
    grid->init_mines();
}

void Game::show_board(){
  //grid->reveal_all();
  grid->print();
}
void Game::show_all(){
  grid->reveal_all();
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
