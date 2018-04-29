//Unit Test #2
//Testing numHandCards() function

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testnumHandCards(){
    int allPass = 0;
  
    struct gameState* state = newGame();

    state->whoseTurn = 1;
    state->handCount[1] = 10;
    if (numHandCards(state) == 10){
        printf("numHandCards(): PASS when test player 1 has 10 cards.\n");
    }
    else{
        printf("numHandCards(): FAIL when test player 1 has 10 cards.\n");
        allPass = -1;
    }

  
    state->whoseTurn = 2;
    state->handCount[2] = 20;
    if (numHandCards(state) == 20){
        printf("numHandCards(): PASS when test player 2 has 20 cards.\n");
    }
    else{
        printf("numHandCards(): FAIL when test player 2 has 20 cards.\n");
        allPass = -1;
    }


    state->whoseTurn = 3;
    state->handCount[3] = 30;
    if (numHandCards(state) == 30){
        printf("numHandCards(): PASS when test player 3 has 30 cards.\n");
    }
    else{
        printf("numHandCards(): FAIL when test player 3 has 30 cards.\n");
        allPass = -1;
    }


    state->whoseTurn = 4;
    state->handCount[4] = 40;
    if (numHandCards(state) == 40){
        printf("numHandCards(): PASS when test player 4 has 40 cards.\n");
    }
    else{
        printf("numHandCards(): FAIL when test player 4 has 40 cards.\n");
        allPass = -1;
    }

    if(allPass == 0){
        printf("\nALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testnumHandCards();
    return 0;
}



