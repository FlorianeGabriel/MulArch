
CC = gcc
CFLAGS = -std=gnu99 -O3 -fopenmp -Wall

all: assignment2 assignment2FirstTry assignment2FirstTryNoIF assignment2Tiles1 assignment2TilesBest

assignment2: assignment2.c utility.h algorithm.c
	$(CC) $(CFLAGS) $< -o $@

assignment2FirstTry: assignment2FirstTry.c utility.h algorithmFirstTry.c
	$(CC) $(CFLAGS) $< -o $@
	
assignment2FirstTryNoIF: assignment2FirstTryNoIF.c utility.h algorithmFirstTryNoIF.c
	$(CC) $(CFLAGS) $< -o $@
	
assignment2Tiles1: assignment2Tiles1.c utility.h algorithmTiles1.c
	$(CC) $(CFLAGS) $< -o $@
	
assignment2TilesBest: assignment2TilesBest.c utility.h algorithmTilesBest.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f assignment2
	rm -f assignment2FirstTry
	rm -f assignment2FirstTryNoIF
	rm -f assignment2Tiles1
	rm -f assignment2TilesBest
