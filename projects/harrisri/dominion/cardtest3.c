//Card Test #3
//Testing great hall card

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

// void greatHallEffect(int handPos, struct gameState *state, int currentPlayer){
//   //+1 Card
//   drawCard(currentPlayer, state);

//   //+1 Actions
//   int actions = state->numActions; //BUG: should be state->numActions++; Remove next line
//   actions += 1;
//   //discard card from hand
//   discardCard(handPos, currentPlayer, state, 0);
// }


void testGreatHallEffect(){
	int i;
    int allPass = 0;
    struct gameState* state = newGame();
    state->numPlayers = 2;
    int player = whoseTurn(state);

    state->hand[player][0] = great_hall;
    state->hand[player][1] = treasure_map;
    state->handCount[player] = 2;

    state->deck[player][0] = baron;
    state->deckCount[player] = 1;

    state->discard[player][0] = sea_hag;
    state->discardCount[player] = 1;
    int bonus = 0;
    int* bonusptr = &bonus;

    

    /*****************************************************************
    test that num actions is incremented.
    *****************************************************************/
    int initialNumActions = state->numActions;  
    cardEffect(great_hall,0,0,0,state,0,bonusptr);
    int afterNumActions = state->numActions;  

    if(afterNumActions > initialNumActions){
        printf("greatHallEffect(): PASS when testing numActions being incremented.\n");
    }
    else{
        printf("greatHallEffect(): FAIL when testing numActions being incremented.\n");
        allPass = -1;
    }


    /*****************************************************************
    test great_hall is properly discarded.
    *****************************************************************/

    int discarded = 1;
    for (i = 0; i < state->playedCardCount; ++i)
    {
        if(state->playedCards[i] == great_hall){
            discarded = 0;
        }
    }

    int handdiscarded = 0;
    for (i = 0; i < state->handCount[player]; ++i)
    {
        if(state->hand[player][i] == great_hall){
            handdiscarded = 1;
        }
    }

    if(discarded == 0 && handdiscarded == 0){
        printf("greatHallEffect(): PASS when testing that great hall was properly discarded.\n");
    }
    else{
        printf("greatHallEffect(): FAIL when testing that great hall was properly discarded.\n");
        allPass = -1;
    }



    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testGreatHallEffect();
    return 0;
}



