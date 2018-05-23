/****************************************************************************************
 * Author: Riley Harrison
 * Date: 5/12/18
 * Description: Randomly generated test cases for great Hall card implementation.
 ****************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include "interface.h"
#include <time.h>
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

void checkgreatHall(int n, int handPos,struct gameState *post, int currentPlayer,int *deckFail, int *handFail, int* discardFail, int *numActionFail) {
	int i;

	//save gamestate
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));

	//"play" greatHall with post gamestate
	greatHallEffect(handPos, post, currentPlayer);

	//correct implemnentation of greatHall card.
	//This will be used to "play" greatHall card on the pre gamestate.
	//+1 Card
	drawCard(currentPlayer, &pre);

	//+1 Actions
	pre.numActions++;

	//discard card from hand
	discardCard(handPos, currentPlayer, &pre, 0);
	//end of correct implementation of greatHall card



	//check that the hands, decks, and discard piles are the same.  They should be if greatHall functions properly.
	for (i = 0; i < pre.handCount[currentPlayer]; ++i)
	{
		if(pre.hand[currentPlayer][i] != post->hand[currentPlayer][i]){
			*handFail += 1;
			break;
		}
	}	

	for (i = 0; i < pre.deckCount[currentPlayer]; ++i)
	{
		if(pre.deck[currentPlayer][i] != post->deck[currentPlayer][i]){
			*deckFail += 1;
			break;
		}
	}	

	for (i = 0; i < pre.discardCount[currentPlayer]; ++i)
	{
		if(pre.discard[currentPlayer][i] != post->discard[currentPlayer][i]){
			*discardFail += 1;
			break;
		}
	}

	if (pre.numActions != post->numActions){
		*numActionFail +=1;
	}

}


int main(int argc, char const *argv[])
{
	//Number of tests we would like to run.
	int numTests = 2000;

	//k here holds all of the cards allowed in this randomized game.
	int k[13] = {copper, gold, silver, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	//variable definitions
	struct gameState G;
	int card, n, i, deckCount, handCount, discardCount, deckFail, handFail, discardFail, numActionFail;
	int player = 0;
	deckFail = 0;
	handFail = 0;
	discardFail = 0;
	numActionFail = 0;


	printf ("Testing greatHall.\n");
	printf ("RANDOM TESTS.\n");

	srand(time(NULL));   //seed for rand() 

	for (n = 0; n < numTests; n++) {
		//get random deckCounts, discardCounts, and handCounts to be used in new GameState
		deckCount = rand() % (MAX_DECK + 1);
		discardCount = rand() % (MAX_DECK + 1);
		handCount = rand() % (MAX_HAND + 1);
		G.deckCount[player] = deckCount;
		G.handCount[player] = handCount;
		G.discardCount[player] = discardCount;

		//fill up deck, hand, and discard with cards
		for (i = 0; i < deckCount; ++i)
		{
			card = rand() % 13; //num elements in k.
			G.deck[player][i] = k[card];
		}

		for (i = 0; i < discardCount; ++i)
		{
			card = rand() % 13; //num elements in k.
			G.discard[player][i] = k[card];
		}

		for (i = 0; i < handCount; ++i)
		{
			card = rand() % 13; //num elements in k.
			G.hand[player][i] = k[card];
		}

		G.hand[player][0] = great_hall;

		//check how the greatHall card works with this randomly generated gamestate.
		checkgreatHall(n + 1, 0, &G, player, &deckFail, &handFail, &discardFail, &numActionFail);
	}
	
	//print results.
	printf("Hand Equivalency Tests: %d/%d FAIL\n", handFail, numTests);
	printf("Deck Equivalency Tests: %d/%d FAIL\n", deckFail, numTests);
	printf("Discard Equivalency Tests: %d/%d FAIL\n", discardFail, numTests);
	printf("Number Actions Equivalency Tests: %d/%d FAIL\n", numActionFail, numTests);
	
	return 0;
}