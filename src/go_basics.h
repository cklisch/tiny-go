#ifndef GO_BASICS_H
#define GO_BASICS_H

#include "stdlib.h"

typedef int tyle;

typedef struct state_t {
  uint size;
  tyle** board;
  uint till_end;
} state_t;

state_t* init_game(uint);
int place_stone(state_t*, uint, uint);
int remove_group(state_t*, uint, uint);
void end_round(state_t*);
void end_game(state_t*);
int auto_remove(state_t* s, uint x, uint y);

#endif
