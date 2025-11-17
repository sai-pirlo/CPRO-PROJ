#include "game.h"
void initializegame(struct gamestate *game) {
    for (int r = 0; r < boardsize; r++) {
        for (int c = 0; c < boardsize; c++) {
            game->board[r][c] = dot_none;
        }
    }
game->numredlinks = 0;
game->numblacklinks = 0;
game->currentplayer = player_red;
    
    printf("========================\n");
    printf("=== Welcome to Twixt!=== \n");
    printf("========================\n");
    printf("red's borders are rows 1 and 24.\n");
    printf("black's borders are columns 1 and 24.\n");
    printf(" red player starts.\n");
}

void printboard(const struct gamestate *game) {
    printf("\n    ");  
    for (int c = 0; c < boardsize; c++) {
        printf("%3d", c + 1); 
    }
    printf("\n");
    for (int r = 0; r < boardsize; r++) {
        printf("%2d |", r + 1); 
        for (int c = 0; c < boardsize; c++) {
            char symbol = 'o';
            if (game->board[r][c] == dot_red) {
                symbol = 'R';
            } else if (game->board[r][c] == player_black) {
                symbol = 'B';
            }
            printf(" %c ", symbol);
        }
        printf("|\n"); 
    }}

void altturn(struct gamestate *game) {
   game->currentplayer = (game->currentplayer == player_red) ? player_black : player_red;
}
