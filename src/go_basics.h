#ifndef GO_BASICS_H
#define GO_BASICS_H

#include "stdlib.h"

typedef int tyle;

typedef struct state_t {
  uint size;
  tyle** board;
  uint till_end;
} state_t;

state_t init_game(uint size);
void end_round(state_t game);

#endif
