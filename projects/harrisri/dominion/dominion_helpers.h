#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

//effect refactors
void adventurerEffect(int drawntreasure,struct gameState *state, int currentPlayer,int temphand[MAX_HAND], int z);
void smithyEffect(int handPos, struct gameState *state, int currentPlayer);
void greatHallEffect(int handPos, struct gameState *state, int currentPlayer);
int embargoEffect(int choice1, struct gameState *state, int handPos, int currentPlayer);
void outpostEffect(int handPos, struct gameState *state, int currentPlayer);
#endif
