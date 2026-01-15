#include "snake.h"
#include <ncurses.h>
#include <stdlib.h>


int main( int argc, char ** argv ){
  int c, maxy, maxx, centery, centerx;
  size_t snakers;
  initscr();              // Start ncurses
  cbreak();               // Switch off input buffering
  curs_set(FALSE);        // Don't place a cursor on the screen
  getmaxyx(stdscr, maxy, maxx); // Window dimensions
  WINDOW *gameWin = newwin(maxy /2, maxx /2, maxy /4, maxx / 4); // Initialize Arena (25% of full window)
  getmaxyx(gameWin, centery, centerx); // Arena dimensions
  struct Snake fruit;
  fruit.y = rand() % centery;
  fruit.x = rand() % centerx;
  centery /= 2;
  centerx /= 2;
  struct Snake body[100] = { 0 }; // Initialize Snake
  snakers = 3;
  for(size_t i = 0; i < snakers; i++){
    body[i].y = centery;
    body[i].x = centerx;
  }
  keypad(gameWin, TRUE);
  halfdelay(TRUE);
  while (1) {
    c = wgetch(gameWin);
    direction(body, c, snakers, gameWin);
    wclear(gameWin);
    box(gameWin, 0, 0);
    snaking(gameWin, body, snakers);
    mvwaddch(gameWin, fruit.y, fruit.x, '*');
}
  delwin(gameWin);
  endwin();
}

