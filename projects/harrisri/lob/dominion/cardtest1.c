//Card Test #1
//Testing smithy card

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

// void smithyEffect(int handPos, struct gameState *state, int currentPlayer){
//   //+3 Cards
//   int i;
//   for (i = 0; i < 4; i++){ //BUG: 4 changed to 3.
//     drawCard(currentPlayer, state);
//   }
//   //discard card from hand
//   discardCard(handPos, currentPlayer, state, 0);
// }
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus

void testSmithyEffect(){
	  int i;
    int allPass = 0;
    struct gameState* state = newGame();
    state->numPlayers = 2;
    int player = whoseTurn(state);

    state->hand[player][0] = smithy;
    state->hand[player][1] = treasure_map;
    state->handCount[player] = 2;


    state->deck[player][1] = baron;
    state->deck[player][2] = baron;
    state->deck[player][3] = baron;
    state->deck[player][4] = baron;
    state->deck[player][4] = baron;
    
    int previousDeckCount = state->deckCount[player] = 4;


    //test that 3 cards were added
    int bonus = 0;
    int* bonusptr = &bonus;
    cardEffect(smithy,0,0,0,state,0,bonusptr);

    if(state->handCount[player]== 4){
    	printf("smithyEffect(): PASS when drawing 3 cards.\n");
    }
    else{
    	printf("smithyEffect(): FAIL when drawing 3 cards. handCount should be 4, currently is %d\n",state->handCount[player]);
   		allPass = -1;
    }

    //test that cards came from deck
  	if(previousDeckCount > state->deckCount[player]){
    	printf("smithyEffect(): PASS drawn cards came from deck.\n");
    }
    else{
    	printf("smithyEffect(): FAIL drawn cards did not come from deck.\n");
   		allPass = -1;
    }

    //test that smithy was removed from hand
    int pass = 0;
   	for (i = 0; i < state->handCount[player]; ++i)
   	{
   		if(state->hand[player][i] == smithy){
   			pass = 1;
   		}
   	}

   	if (pass == 0){
    	printf("smithyEffect(): PASS when removing smithy from hand.\n");
   	}

   	else{
    	printf("smithyEffect(): FAIL when removing smithy from hand.\n");
   		allPass = -1;
   	}

    //test that smithy was added to played pile.
    pass = 1;
   	for (i = 0; i < state->playedCardCount; ++i)
   	{
   		if(state->playedCards[i] == smithy){
   			pass = 0;
   		}
   	}

   	if (pass == 0){
    	printf("smithyEffect(): PASS when adding smithy to played pile.\n");
   	}

   	else{
    	printf("smithyEffect(): FAIL when adding smithy to played pile.\n");
   		allPass = -1;
   	}


    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testSmithyEffect();
    return 0;
}



