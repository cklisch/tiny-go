#include "stdio.h"
#include "go_basics.h"
#include "go_graphics.h"
#include "go_test.h"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("too many arguments\n");
  }
  int size;
  sscanf(argv[1],"%d", &size);

  state_t* game = init_game(size);
  uint x, y;
  int score = 0;
  int player;
  while(game->till_end) {
    print_go(game);
    player = (game->till_end % 2) + 1;
    printf("place a stone player: %d\n", player);
    scanf("%u %u", &x, &y);
    if(!place_stone(game, x, y)) {
      printf("Invalid move! Player #%d looses!\n", player);
      return 0;
    }
    score += auto_remove(game, x, y);
    print_go(game);
    printf("current score %d, moves to go %d\n", score, game->till_end);
  }
  printf("test pass: %d\n", test());
  return 1;
}
