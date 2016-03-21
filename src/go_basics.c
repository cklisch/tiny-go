#include "go_basics.h"

/* Return the initial board for a round. All positions are empty
** (initialized with 0).
*/
state_t init_game(uint size)
{
  state_t s;
  s.size = size;
  s.board = (tyle**)malloc(sizeof(tyle*) * size);
  for (uint i = 0; i < size; i++) {
    s.board[i] = (tyle*)calloc(size, sizeof(tyle));
  }
  s.till_end = size * size - 1;
  return s;
}

/* Reset teh game state after a round is done
*/
void end_round(state_t board)
{
  uint size = board.size;
  tyle** T = board.board;
  for (int i = 0; i < size; i++) {
    for (uint j = 0; j < size; j++) {
      T[i][j] = 0;
    }
  }
}
