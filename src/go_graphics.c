#include "go_graphics.h"

/* Print the board state.
*/
int print_go(state_t board)
{
  tyle** T = board.board;
  for (int i = 0; i < size; i++) {
    for (uint j = 0; j < size; j++) {
      printf("%d",T[i][j]);
    }
    printf("\n");
  }
  return 1;
}
