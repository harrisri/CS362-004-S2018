//Unit Test #4
//Testing fullDeckCount() function

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// int fullDeckCount(int player, int card, struct gameState *state) {
//   int i;
//   int count = 0;

//   for (i = 0; i < state->deckCount[player]; i++)
//     {
//       if (state->deck[player][i] == card) count++;
//     }

//   for (i = 0; i < state->handCount[player]; i++)
//     {
//       if (state->hand[player][i] == card) count++;
//     }

//   for (i = 0; i < state->discardCount[player]; i++)
//     {
//       if (state->discard[player][i] == card) count++;
//     }

//   return count;
// }


void testfullDeckCount(){
    int i;
    int allPass = 0;

    struct gameState* state1 = newGame();
    struct gameState* state2 = newGame();
    struct gameState* state3 = newGame();
    int player1 = 1;
    int player2 = 2;
    int player3 = 3;

    //one card in each deck, hand, and discard
    for (i = 0; i < 500; ++i) //500 is max deck/max hand
    {
        state1->deck[player1][i] = duchy;
        state1->hand[player1][i] = duchy;
        state1->discard[player1][i] = duchy;
        state1->deckCount[player1]++;
        state1->handCount[player1]++;
        state1->discardCount[player1]++;
    }    

    //0 cards in anything
    for (i = 0; i < 500; ++i) //500 is max deck/max hand
    {
        state2->deck[player2][i] = -9999;
        state2->hand[player2][i] = -9999;
        state2->discard[player2][i] = -9999;
    }

    state2->deckCount[player2] = 0;
    state2->handCount[player2] = 0;
    state2->discardCount[player2] = 0;


    //0 out player 3 first.
    for (i = 0; i < 500; ++i) //500 is max deck/max hand
    {
        state3->deck[player3][i] = -9999;
        state3->hand[player3][i] = -9999;
        state3->discard[player3][i] = -9999;
    }

    state3->deck[player3][0] = province;
    state3->hand[player3][0] = smithy;
    state3->discard[player3][0] = baron;

    state3->deckCount[player3]++;
    state3->handCount[player3]++;
    state3->discardCount[player3]++;


    
    int duchycount = fullDeckCount(player1, duchy, state1);
    if ( duchycount == 1500){
        printf("fullDeckCount(): PASS when 500 copies of dutchy is in each deck, hand, and discard.\n");
    }
    else{
        printf("fullDeckCount(): FAIL when 500 copies of dutchy is in each deck, hand, and discard. %d copies returned.\n",duchycount);
        allPass = -1;
    }

  
    duchycount = fullDeckCount(player2, duchy, state2);
    if (duchycount == 0){
        printf("fullDeckCount(): PASS when 0 copies of dutchy is in each deck, hand, and discard.\n");
    }
    else{
        printf("fullDeckCount(): FAIL when 0 copies of dutchy is in each deck, hand, and discard. %d copies returned.\n",duchycount);
        allPass = -1;
    }

    
    int provinceCount = fullDeckCount(player3, province, state3);
    int smithyCount = fullDeckCount(player3, smithy, state3);
    int baronCount = fullDeckCount(player3, baron, state3);

    if (provinceCount == 1){
        printf("fullDeckCount(): PASS when 1 province is in deck only.\n");
    }
    else{ 
        allPass = -1;
        printf("fullDeckCount(): FAIL when 1 province is in deck only. %d copies returned.\n", provinceCount);
    }    

    if (smithyCount == 1){
        printf("fullDeckCount(): PASS when 1 smithy is in hand only.\n");
    }
    else{ 
        allPass = -1;
        printf("fullDeckCount(): FAIL when 1 smithy is in hand only. %d copies returned.\n", smithyCount);
    }    

    if (baronCount == 1){
        printf("fullDeckCount(): PASS when 1 baron is in discard only.\n");
    }
    else{ 
        allPass = -1;
        printf("fullDeckCount(): FAIL when 1 baron is in discard only. %d copies returned.\n", baronCount);
    }

    if(allPass == 0){
        printf("ALL TESTS PASSED.\n");
    }

}

int main(int argc, char *argv[])
{
    testfullDeckCount();
    return 0;
}


