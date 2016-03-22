#include "go_graphics.h"
#include "stdio.h"

/* Print the board state.
*/
int print_go(state_t* board)
{
  uint size = board->size;
  tyle** T = board->board;
  for (uint i = 0; i < size; i++) {
    for (uint j = 0; j < size; j++) {
      printf("%d",T[i][j]);
    }
    printf("\n");
  }
  return 1;
}
