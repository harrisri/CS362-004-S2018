/****************************************************************************************
 * Author: Riley Harrison
 * Date: 5/12/18
 * Description: Randomly generated test cases for adventure card implementation.
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

void checkAdventurer(int n, int drawntreasure,struct gameState *post, int currentPlayer,int temphand[MAX_HAND], int z, int *deckFail, int *handFail, int* discardFail) {
	int i;

	//save gamestate
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));

	//"play" adventurer with post gamestate
	adventurerEffect(drawntreasure, post, currentPlayer, temphand, z);

	//correct implemnentation of adventurer card.
	//This will be used to "play" adventurer card on the pre gamestate.
	while(drawntreasure<2){
		if (pre.deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, &pre);
		}
			drawCard(currentPlayer, &pre);
			int cardDrawn = pre.hand[currentPlayer][pre.handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
			drawntreasure++; 
		} 
		else{
			temphand[z]=cardDrawn;
			pre.handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while(z-1>=0){
		pre.discard[currentPlayer][pre.discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
	}
	//end of correct implementation of adventurer card


	//check that the hands, decks, and discard piles are the same.  They should be if adventurer functions properly.
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

}


int main(int argc, char const *argv[])
{
	//Number of tests we would like to run.
	int numTests = 2000;

	//k here holds all of the cards allowed in this randomized game.
	int k[13] = {copper, gold, silver, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	//variable definitions
	int temphand[MAX_HAND];
	struct gameState G;
	int card, n, i, deckCount, handCount, discardCount, deckFail, handFail, discardFail;
	int player = 0;
	deckFail = 0;
	handFail = 0;
	discardFail = 0;


	printf ("Testing adventurer.\n");
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

		//check how the adventurer card works with this randomly generated gamestate.
		checkAdventurer(n + 1, 0, &G, player, temphand, 0, &deckFail, &handFail, &discardFail);
	}
	
	//print results.
	printf("Hand Equivalency Tests: %d/%d. FAIL\n", handFail, numTests);
	printf("Deck Equivalency Tests: %d/%d. FAIL\n", deckFail, numTests);
	printf("Discard Equivalency Tests: %d/%d FAIL.\n", discardFail, numTests);
	
	return 0;
}