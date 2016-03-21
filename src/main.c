#include "stdio.h"
#include "go_basics.h"
#include "go_graphics.h"

int main(int argc, char const *argv[])
{
  state_t game;
  for (int i = 0; i < 10; i++) {
    game = game_init(19);
    free(game.board);
  }

return 0;
}
