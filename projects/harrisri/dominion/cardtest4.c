//Card Test #4
//Testing outpost card

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

// void outpostEffect(int handPos, struct gameState *state, int currentPlayer){
//   //set outpost flag
//   state->outpostPlayed++;

//   //discard card
//   discardCard(handPos, currentPlayer, state, 0);
// }

// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)


void testoutpostEffect(){
	int i;
    int allPass = 0;
    struct gameState* state = newGame();
    state->numPlayers = 2;
    int player = whoseTurn(state);

    state->hand[player][0] = outpost;
    state->handCount[player] = 1;

    state->deck[player][0] = baron;
    state->deck[player][1] = baron;
    state->deck[player][2] = baron;
    state->deck[player][3] = baron;
    state->deck[player][4] = baron;
    state->deck[player][5] = baron;
    state->deckCount[player] = 6;

    int bonus = 0;
    int* bonusptr = &bonus;

    

    /*****************************************************************
    test that num actions is incremented.
    *****************************************************************/
    cardEffect(outpost,0,0,0,state,0,bonusptr);

    if(state->outpostPlayed > 0){
        printf("outpostEffect(): PASS when testing outPostPlayed being incremented.\n");
    }
    else{
        printf("outpostEffect(): FAIL when testing outPostPlayed being incremented.\n");
        allPass = -1;
    }

    /*****************************************************************
    test outpost is properly discarded.
    *****************************************************************/

    int discarded = 1;
    for (i = 0; i < state->playedCardCount; ++i)
    {
        if(state->playedCards[i] == outpost){
            discarded = 0;
        }
    }

    int handdiscarded = 0;
    for (i = 0; i < state->handCount[player]; ++i)
    {
        if(state->hand[player][i] == outpost){
            handdiscarded = 1;
        }
    }

    if(discarded == 0 && handdiscarded == 0){
        printf("outpostEffect(): PASS when testing that outpost was properly discarded.\n");
    }
    else{
        printf("outpostEffect(): FAIL when testing that outpost was properly discarded.\n");
        allPass = -1;
    }


    /*****************************************************************
    test that only 3 cards are drawn
    *****************************************************************/
    endTurn(state);
    if(state->handCount[player] == 3){
        printf("outpostEffect(): PASS only drew 3 cards.\n");
    }
    else{
        printf("outpostEffect(): FAIL drew more than 3 cards.\n");
        allPass = -1;
    }

    /*****************************************************************
    test for extra turn
    *****************************************************************/
    endTurn(state);
    if(state->outpostTurn != 0){
        printf("outpostEffect(): PASS taking extra turn.\n");
    }
    else{
        printf("outpostEffect(): FAIL no extra turn given.\n");
        allPass = -1;
    }

    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testoutpostEffect();
    return 0;
}



