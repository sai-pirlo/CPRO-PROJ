#define twixt_h

#include <stdio.h> 


#define boardsize 20
#define maxlinks 1000
enum dot {
    dot_none,    
    dot_red,     
    dot_black    
};

enum player {
    player_red,
    player_black
};

struct dots {
    int row;
    int column;
};

struct link {
    struct dots p1; 
    struct dots p2; 
};

struct gamestate {
    enum dot board[boardsize][boardsize];
    
   
    struct link redlinks[maxlinks];
    int numredlinks;
    
    struct link blacklinks[maxlinks];
    int numblacklinks;
    

    enum player currentplayer;
} ;


void initializegame(struct gamestate *game){

};


void printboard(const struct gamestate *game){

};


void altturn(struct gamestate *game){

};


void clearinputbuffer(void){

};

