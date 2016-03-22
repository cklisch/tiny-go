#include "go_test.h"
#include "go_graphics.h"
#include"stdio.h"


 int test1()
 {
   state_t* game = init_game(3);
   place_stone(game, 0, 0);
   place_stone(game, 0, 1);
   place_stone(game, 1, 0);
   place_stone(game, 1, 1);
   place_stone(game, 2, 0);
   place_stone(game, 2, 1);

   int removed = remove_group(game, 0, 0);
   if(removed == 3) {
    return 1;
   }
   return 0;
 }

 int test2()
 {
   state_t* game = init_game(5);
   int matrix[5][5] = {
     {0,0,0,0,0},
     {0,0,0,0,0},
     {1,1,1,1,1},
     {2,2,1,0,0},
     {1,2,2,1,0}
   };
   for (int i = 0; i < 5; i++) {
     for (int j = 0; j < 5; j++) {
       game->board[i][j] = matrix[i][j];
     }
   }
   int removed = remove_group(game, 3, 0);
   if (removed == -4) {
     return 1;
   }
   return 0;

 }
 int test3()
 {
   state_t* game = init_game(5);
   int matrix[5][5] = {
     {2,2,1,0,0},
     {2,2,1,0,0},
     {1,2,2,1,1},
     {2,2,1,0,0},
     {1,2,2,1,0}
   };
   for (int i = 0; i < 5; i++) {
     for (int j = 0; j < 5; j++) {
       game->board[i][j] = matrix[i][j];
     }
   }
   int removed = remove_group(game, 2, 2);
   if (removed == -10) {
     return 1;
   }
   return 0;

 }

 int test()
 {
   int nr_tests = 3;
   int score = 0;
   score += test1();
   score += test2();
   score += test3();
   return (nr_tests == score);
 }
