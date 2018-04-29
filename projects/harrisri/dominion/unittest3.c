//Unit Test #3
//Testing isGameOver() function

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testisGameOver(){
    int i;
    int allPass = 0;

    struct gameState* state = malloc(sizeof(struct gameState));
    //fill up supply count.
    for (i = 0; i < 25; ++i){
        state->supplyCount[i] = 5;
    }


    state->supplyCount[province] = 0;
    if (isGameOver(state) == 1){
        printf("isGameOver(): PASS when stack of provice cards is empty.\n");
    }
    else{
        printf("isGameOver(): FAIL when stack of provice cards is empty.\n");
        allPass = -1;
    }

    state->supplyCount[province] = 5;
    state->supplyCount[4] = 0;
    state->supplyCount[5] = 0;
    state->supplyCount[6] = 0;

    if (isGameOver(state) == 1){
        printf("isGameOver(): PASS when three supply piles are at 0.\n");
    }
    else{
        printf("isGameOver(): FAIL when three supply piles are at 0.\n");
        allPass = -1;
    }

    state->supplyCount[4] = 5;
    state->supplyCount[5] = 5;
    state->supplyCount[6] = 5;

    if (isGameOver(state) == 0){
        printf("isGameOver(): PASS when game is not yet over.\n");
    }
    else{
        printf("isGameOver(): FAIL when game is not yet over.\n");
        allPass = -1;
    }



    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testisGameOver();
    return 0;
}



