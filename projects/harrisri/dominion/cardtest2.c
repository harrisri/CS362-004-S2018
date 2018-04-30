//Card Test #2
//Testing adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// void adventurerEffect(int drawntreasure,struct gameState *state, int currentPlayer,int temphand[MAX_HAND], int z){
//   while(drawntreasure<2){
//     if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
//       shuffle(currentPlayer, state);
//     }
//     drawCard(currentPlayer, state);
//     int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
//     if (cardDrawn == copper || cardDrawn == silver) //BUG:if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
//       drawntreasure++;
//     else{
//       temphand[z]=cardDrawn;
//       state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
//       z++;
//     }
//   }
      
//   while(z-1>=0){
//     state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
//     z=z-1;
//   }
// }

// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus

void testadventurerEffect(){
    int allPass = 0;
    int i;

    int bonus = 0;
    int* bonusptr = &bonus;

    /*****************************************************************
    test that two treasure ca6rds were added to hand. also tests that 2 coppers work.
    *****************************************************************/
    struct gameState* state1 = newGame();
    state1->numPlayers = 2;
    int player = whoseTurn(state1);
    
    state1->hand[player][0] = adventurer;
    state1->hand[player][1] = treasure_map;
    state1->handCount[player] = 2;   

    state1->deck[player][0] = copper;
    state1->deck[player][1] = baron;
    state1->deck[player][2] = copper;
    state1->deckCount[player] = 3;


    cardEffect(adventurer,0,0,0,state1,0, bonusptr);

    int count = 0;
    for (i = 0; i < state1->handCount[player]; ++i)
    {
        if(state1->hand[player][i] == copper){
            count++;
        }
    }

    if (count == 2)
    {
        printf("adventurerEffect(): PASS when testing if two copper treasure cards were added to hand.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if two copper treasure cards were added to hand.\n");
        allPass = -1;
    }


    /*****************************************************************
    test that two silvers work.
    *****************************************************************/
    struct gameState* state2 = newGame();
    state2->numPlayers = 2;
    player = whoseTurn(state2);

    state2->hand[player][0] = adventurer;
    state2->hand[player][1] = treasure_map;
    state2->handCount[player] = 2; 

    state2->deck[player][0] = silver;
    state2->deck[player][1] = baron;
    state2->deck[player][2] = silver;
    state2->deckCount[player] = 3;

    cardEffect(adventurer,0,0,0,state2,0, bonusptr);

    count = 0;
    for (i = 0; i < state1->handCount[player]; ++i)
    {
        if(state2->hand[player][i] == silver){
            count++;
        }
    }

    if (count == 2)
    {
        printf("adventurerEffect(): PASS when testing if two silver treasure cards were added to hand.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if two silver treasure cards were added to hand.\n");
        allPass = -1;
    }



    /*****************************************************************
    test that two gold work.
    *****************************************************************/
    struct gameState* state3 = newGame();
    state3->numPlayers = 2;
    player = whoseTurn(state3);
    state3->hand[player][0] = adventurer;
    state3->hand[player][1] = treasure_map;
    state3->handCount[player] = 2;

 
    state3->deck[player][0] = gold ;
    state3->deck[player][1] = baron;
    state3->deck[player][2] = gold;
    state3->deck[player][3] = copper;//we shouldnt draw copper.
    state3->deck[player][4] = copper;

    state3->deckCount[player] = 5;

    cardEffect(adventurer,0,0,0,state3,0, bonusptr);
    
    count = 0;
    for (i = 0; i < state3->handCount[player]; ++i)
    {
        if(state3->hand[player][i] == gold){
            count++;
        }
    }

    if (count == 2)
    {
        printf("adventurerEffect(): PASS when testing if two gold treasure cards were added to hand.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if two gold treasure cards were added to hand.\n");
        allPass = -1;
    }


    /*****************************************************************
    test that one copper and one gold works.
    *****************************************************************/
    struct gameState* state4 = newGame();
    state4->numPlayers = 2;
    player = whoseTurn(state4);
    state4->hand[player][0] = adventurer;
    state4->hand[player][1] = treasure_map;
    state4->handCount[player] = 2;


    state4->deck[player][0] = copper;
    state4->deck[player][1] = baron;
    state4->deck[player][2] = gold;
    state4->deck[player][3] = copper;//we shouldnt draw copper.
    state4->deck[player][4] = copper;
    state4->deckCount[player] = 5;

    cardEffect(adventurer,0,0,0,state4,0, bonusptr);
    
    int goldCount = 0;
    int copperCount = 0;
    for (i = 0; i < state4->handCount[player]; ++i)
    {
        if(state4->hand[player][i] == gold){
            goldCount++;
        }
        if(state4->hand[player][i] == copper){
            copperCount++;
        }
    }

    if (goldCount == 1 && copperCount == 1)
    {
        printf("adventurerEffect(): PASS when testing if one gold and one copper treasure cards were added to hand.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if one gold and one copper treasure cards were added to hand.\n");
        allPass = -1;
    }

    /*****************************************************************
    test that two treasure cards were added to hand.
    *****************************************************************/
    struct gameState* state5 = newGame();
    state5->numPlayers = 2;
    player = whoseTurn(state5);
    state5->hand[player][0] = adventurer;
    state5->hand[player][1] = treasure_map;
    state5->handCount[player] = 2;

    state5->deck[player][0] = copper;
    state5->deck[player][1] = baron;
    state5->deck[player][2] = silver;
    state5->deckCount[player] = 3;

    cardEffect(adventurer,0,0,0,state5,0, bonusptr);

    copperCount = 0;
    int silverCount = 0;
    for (i = 0; i < state5->handCount[player]; ++i)
    {
        if(state5->hand[player][i] == copper){
            copperCount++;
        }
        if(state5->hand[player][i] == silver){
            silverCount++;
        }
    }

    if (copperCount == 1 && silverCount == 1)
    {
        printf("adventurerEffect(): PASS when testing if one silver and one copper treasure cards were added to hand.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if one silver and one copper treasure cards were added to hand.\n");
        allPass = -1;
    }
    
    /*****************************************************************
    test drawn non-treasure cards are added to discard pile.
    *****************************************************************/
    struct gameState* state6 = newGame();
    state6->numPlayers = 2;
    player = whoseTurn(state6);
    state6->hand[player][0] = adventurer;
    state6->hand[player][1] = treasure_map;
    state6->handCount[player] = 2;
     
    state6->deck[player][0] = baron;
    state6->deck[player][1] = baron;
    state6->deck[player][2] = silver;
    state6->deck[player][2] = copper;
    state6->deckCount[player] = 4;

    state6->discard[player][0] = sea_hag;
    state6->discard[player][1] = sea_hag;   
    state6->discard[player][2] = sea_hag;
    state6->discardCount[player] = 3;    

    cardEffect(adventurer,0,0,0,state6,0, bonusptr);

    count = 0;
    for (i = 0; i < state6->discardCount[player]; ++i)
    {
        if(state6->discard[player][i] == baron){
            count++;
        }
    }

    if(count == 2){
        printf("adventurerEffect(): PASS when testing if drawn (non-treasure cards) were added to discard pile.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if drawn (non-treasure cards) were added to discard pile.\n");
        allPass = -1;
    }   

    /*****************************************************************
    test shuffle.  treasure cards are only in discard pile.
    *****************************************************************/
    struct gameState* state7 = newGame();
    state7->numPlayers = 2;
    player = whoseTurn(state7);
    state7->hand[player][0] = adventurer;
    state7->hand[player][1] = treasure_map;
    state7->handCount[player] = 2;

    state7->deck[player][0] = treasure_map;
    state7->deckCount[player] = 1;

    state7->discard[player][0] = copper;
    state7->discard[player][1] = copper;   
    state7->discard[player][2] = sea_hag;
    state7->discardCount[player] = 3;    

    cardEffect(adventurer,0,0,0,state7,0, bonusptr);

    count = 0;
    for (i = 0; i < state7->handCount[player]; ++i)
    {
        if(state7->hand[player][i] == copper){
            count++;
        }
    }

    if(count == 2){
        printf("adventurerEffect(): PASS when testing if treasure cards only start in discard pile.\n");
    }
    else{
        printf("adventurerEffect(): FAIL when testing if treasure cards only start in discard pile.\n");
        allPass = -1;
    }
    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testadventurerEffect();
    return 0;
}



