#include <stdio.h>
#include "twixt.h"  
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
            clearinputbuffer(); 
            continue;           
        }
        
    
        clearinputbuffer(); 

       
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
            printf("That spot is already taken by a peg.\n");
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
    printf("   Welcome to Twixt!    \n");
    printf("========================\n");
    printf("Red's borders are Rows 1 and 24.\n");
    printf("Black's borders are Cols 1 and 24.\n");
    printf(" Red Player starts.\n");
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
            char symbol = '.';
            
            if (game->board[r][c] == dot_red) {
                symbol = 'R';
            } else if (game->board[r][c] == player_black) {
                symbol = 'B';
            }
            
           
            printf(" %c ", symbol);
        }
        printf("|\n"); 
    }
    

}


void altturn(struct gamestate *game) {
   
    game->currentplayer = (game->currentplayer == player_red) ? player_black : player_red;
}


void clearinputbuffer(void) {
    int c;
    while ((c = getchar()) != '\n' ) {
        
    }
}