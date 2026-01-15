#include <ncurses.h>
#include <stddef.h>
#define SNAKE_HEAD 'O'
#define SNAKE_TAIL 'o'

struct Snake {
  unsigned int y;
  unsigned int x;
};

void direction(struct Snake *s, int , size_t, WINDOW *);
void snaking(WINDOW *, struct Snake *, size_t);
