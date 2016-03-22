#include "go_basics.h"
#include "stdio.h"

tyle** malloc_board(uint size)
{
  tyle** t = (tyle**)malloc(sizeof(tyle*) * size);
  for (uint i = 0; i < size; i++) {
    t[i] = (tyle*)calloc(size, sizeof(tyle));
  }
  return t;
}

void free_board(tyle** T, uint size)
{
  for (uint i = 0; i < size; i++) {
    free(T[i]);
  }
  free(T);
}

/* Return the initial board for a round. All positions are empty
** (initialized with 0).
*/
state_t* init_game(uint size)
{
  state_t* s = (state_t*)malloc(sizeof(state_t));
  s->size = size;
  s->board = malloc_board(size);
  s->till_end = size * size - 1;
  return s;
}

/* Reset teh game state after a round is done
*/
void end_round(state_t* s)
{
  uint size = s->size;
  tyle** T = s->board;
  for (uint i = 0; i < size; i++) {
    for (uint j = 0; j < size; j++) {
      T[i][j] = 0;
    }
  }
  s->till_end = size * size - 1;
}

/* This function has to be called for every init_game when a game ends. Otherwise memory leak.
*/
void end_game(state_t* s)
{
  free_board(s->board, s->size);
  free(s);
}

/* Returns 1 if the stone was correctly placed.
*/
int place_stone(state_t* s, uint x, uint y)
{
  uint size = s->size;
  if (x >= size || y >= size) {
    return 0;
  }
  else if (s->board[x][y] == 0) {
    s->board[x][y] = (s->till_end % 2) + 1;
    s->till_end--;
    return 1;
  }
  else {
    return 0;
  }
}
/* return 0 if remove was invaled (group had a libety)
*/
int recursice_remove(state_t* s, uint x, uint y, tyle** helper, int* score, tyle color)
{

  uint size = s->size;
  tyle** board = s->board;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      uint _x = x + i; uint _y = y + j;
      if (_x >= size || _y >= size || ((i == j || i == (-j)) && (i != 0 && j != 0))) {
      }
      else if (board[_x][_y] == 0 && helper[_x][_y] == 0) {
        printf("freedom at %d %d\n", _x, _y);
        return 0;
      }
      else if (board[_x][_y] == color && helper[_x][_y] == 0) {
        helper[_x][_y] = 1;
        board[_x][_y] = 0;
        (*score) += 1;
        if (!recursice_remove(s, _x, _y, helper, score, color)) {
          printf("rec error\n");
          return 0;
        }
      }
    }
  }
  return 1;
}

/*Returns number of removed stones, poitive for player 1, negative for player 2.
** 0 when remove was invalid.
*/
int remove_group(state_t* s, uint x, uint y)
{
  uint size = s->size;
  if (x >= size || y >= size) {
    return 0;
  }
  tyle color = s->board[x][y];
  if (color == 0) {
    return 0;
  }

  tyle** helper = malloc_board(size);
  int score = 0;
  if (!recursice_remove(s, x, y, helper, &score, color)) {
    return 0;
  }
  if (color == 2) {
    return score * (-1);
  }
  else {
    return score;
  }
}
