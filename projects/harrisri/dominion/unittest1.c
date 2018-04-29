//Unit Test #1
//Testing whoseTurn() function

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testWhoseTurn(){
    struct gameState* state = malloc(sizeof(struct gameState));
    state->whoseTurn = 0;

    int allPass = 0;

    if (whoseTurn(state) == 0){
        printf("whoseTurn(): PASS when test player 0's turn.\n");
    }
    else{
        printf("whoseTurn(): FAIL when test player 0's turn.\n");
        allPass = -1;
    }

    state->whoseTurn = 1;
    if (whoseTurn(state) == 1){
        printf("whoseTurn(): PASS when test player 1's turn.\n");
    }
    else{
        printf("whoseTurn(): FAIL when test player 1's turn.\n");
        allPass = -1;
    }

    state->whoseTurn = 100;
    if (whoseTurn(state) == 100){
        printf("whoseTurn(): PASS when test player 100's turn.\n");
    }
    else{
        printf("whoseTurn(): FAIL when test player 100's turn.\n");
        allPass = -1;
    }

    state->whoseTurn = -1;
    if (whoseTurn(state) == -1){
        printf("whoseTurn(): PASS when test player -1's turn.\n");
    }
    else{
        printf("whoseTurn(): FAIL when test player -1's turn.\n");
        allPass = -1;
    }

    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testWhoseTurn();
    return 0;
}



