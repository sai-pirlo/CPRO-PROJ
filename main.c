#include <stdio.h>
#include "game.h"  
int main() {
    struct gamestate game;
    initializegame(&game);

    int gamerunning = 1;
    while (gamerunning) {
        
        printboard(&game);
        
        if (game.currentplayer == player_red) {
            printf("Turn: ** RED **\n");
        } else {
            printf("Turn: ** BLACK **\n");
        }

       
        int row, col;
        printf("Enter peg location (row col): ");
        
        
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Please enter two numbers (e.g., '10 12').\n");
            continue;           
        }
        
    

       
        int rowindex = row - 1;
        int colindex = col - 1;

        
        if (rowindex < 0 || rowindex >= boardsize || colindex < 0 || colindex >= boardsize) {
            printf("Move out of bounds. Must be between 1 and 24.\n");
            continue; 
        }

        
        if (game.currentplayer == player_red) {
            if (colindex == 0 || colindex == boardsize - 1) {
                printf("Invalid move. Red cannot play in Black's border columns (1 and 24).\n");
                continue;
            }
        } else { 
            if (rowindex == 0 || rowindex == boardsize - 1) {
                printf("Invalid move. Black cannot play in Red's border rows (1 and 24).\n");
                continue;
            }
        }

        
        if (game.board[rowindex][colindex] != dot_none) {
            printf("That spot is already taken.\n");
            continue;
        }


        if (game.currentplayer == player_red) {
            game.board[rowindex][colindex] = dot_red;
        } else {
            game.board[rowindex][colindex] = dot_black;
        }
        
        printf("Placed peg at (%d, %d)\n", row, col);

     
        if (gamerunning) {
            altturn(&game);
        }
    }

    return 0;
}
