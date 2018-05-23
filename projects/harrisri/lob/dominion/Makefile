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

rand1: randomtestadventurer.c dominion.o rngs.o interface.o
	gcc -o rand1.exe -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS) 

rand2: randomtestcard1.c dominion.o rngs.o interface.o
	gcc -o rand2.exe -g randomtestcard1.c dominion.o rngs.o interface.o $(CFLAGS) 

rand3: randomtestcard2.c dominion.o rngs.o interface.o
	gcc -o rand3.exe -g randomtestcard2.c dominion.o rngs.o interface.o $(CFLAGS) 

card1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o card1.exe -g cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)

card2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o card2.exe -g cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)

card3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o card3.exe -g cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)

card4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o card4.exe -g cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)

randomTests: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.o rngs.o interface.o

	echo "############################# randomtestcard1.out: Smithy #########################################" >> randomtestcard1.out 
	gcc -o rand1.exe -g randomtestcard1.c dominion.o rngs.o interface.o $(CFLAGS)
	./rand1.exe >> randomtestcard1.out 
	echo "############################################## gcov ################################################\n" >> randomtestcard1.out 
	gcov -f -b dominion.c >> randomtestcard1.out 
	echo "\n" >> randomtestcard1.out 

	echo "############################# randomtestcard2.out: Great Hall #####################################" >> randomtestcard2.out 
	gcc -o rand2.exe -g randomtestcard2.c dominion.o rngs.o interface.o $(CFLAGS)
	./rand2.exe >> randomtestcard2.out 
	echo "############################################## gcov ################################################\n" >> randomtestcard2.out 
	gcov -f -b dominion.c >> randomtestcard2.out 
	echo "\n" >> randomtestcard2.out 

	echo "############################# randomtestadventurer.out: Adventurer ################################" >> randomtestadventurer.out 
	gcc -o rand3.exe -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)
	./rand3.exe >> randomtestadventurer.out 
	echo "############################################## gcov ################################################\n" >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out  
	echo "\n" >> randomtestadventurer.out  
	
	make cleanUnitTests

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

cleanUnitTests:
	rm -f *.o *.gcov *.gcda *.gcno *.exe


clean:
	rm -f *.o  playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
