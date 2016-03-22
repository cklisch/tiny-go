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
  uint rem_nr;
  int score = 0;
  int removed;
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
    print_go(game);
    printf("type the number of groups you want to remove\n");
    scanf("%u", &rem_nr);
    for (uint i = 0; i < rem_nr; i++) {
      printf("Type coorinate of group element\n");
      scanf("%u %u", &x, &y);
      removed = remove_group(game, x, y);
      if(removed == 0) {
        printf("Invalid remove Player #%d looses!\n", player);
        return 0;
      }
      else {
        score += removed;
      }
      print_go(game);
      printf("\n");
    }
    printf("current score %d, moves to go %d\n", score, game->till_end);
  }
  printf("test pass: %d\n", test());

return 1;
}
