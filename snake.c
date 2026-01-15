#include "snake.h"
#define NORTH 1
#define SOUTH 2 
#define WEST 3
#define EAST 4

void direction(struct Snake *s, int k, size_t len, WINDOW *gameWindow){
  int south, east;
  uint8_t mode;
  getmaxyx(gameWindow, south, east); // Getting boundaries 
  switch(k){                         // Getting mode
    case KEY_UP:
      mode = (mode == SOUTH) ? SOUTH : NORTH; 
      break;
    case KEY_DOWN:
      mode = (mode == NORTH) ? NORTH : SOUTH;
      break;
    case KEY_LEFT:
      mode = (mode == EAST) ? EAST : WEST;
      break;
    case KEY_RIGHT:
      mode = (mode == WEST) ? WEST : EAST;
      break;
    default:
      return;
  }
  for(size_t i = len - 1; i > 0; i--)
    s[i] = s[i-1];
  if (s[0].y == 0){                 // Setting boundaries...
    s[0].y += south - 1;
  }else if(s[0].y == south){
    s[0].y -= south - 1;
  }else if(s[0].x == 0){
    s[0].x += east - 1;
  }else if(s[0].x == east){
    s[0].x -= east - 1;
  }
  if (mode == NORTH)
    s->y -= 1; 
  else if (mode == SOUTH)
    s->y += 1;
  else if (mode == EAST)
    s->x += 1;
  else if (mode == WEST)
    s->x -= 1;
}

void snaking(WINDOW *gameWindow, struct Snake *s, size_t len){
  mvwaddch(gameWindow, s[0].y, s[0].x, SNAKE_HEAD);
  for(size_t i = 1; i < len; i++)
    mvwaddch(gameWindow, s[i].y, s[i].x, SNAKE_TAIL);
}
