CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unit1: unittest1.c dominion.o rngs.o
	gcc -o unit1 -g unittest1.c dominion.o rngs.o $(CFLAGS) 

unit2: unittest2.c dominion.o rngs.o
	gcc -o unit2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unit3: unittest3.c dominion.o rngs.o
	gcc -o unit3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unit4: unittest4.c dominion.o rngs.o
	gcc -o unit4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

card1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o card1 -g cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)

card2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o card2 -g cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)

card3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o card3 -g cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)

card4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o card4 -g cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
