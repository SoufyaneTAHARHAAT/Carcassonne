CC = gcc
CFLAGS = -Wall -Wextra  -pedantic -std=c11 -g
LDFLAGS = -lm
BIN = bin

target: main.o Stack.o Tile.o Grid.o Game.o Player.o Meeple.o
	$(CC) $(BIN)/main.o $(BIN)/Stack.o $(BIN)/Tile.o ${BIN}/Grid.o ${BIN}/Player.o ${BIN}/Meeple.o ${BIN}/Game.o -o $(BIN)/exe $(LDFLAGS)

run: 
	$(BIN)/./exe
debug:
	valgrind -s --track-origins=yes --leak-check=full $(BIN)/./out

main.o: src/main.c 
	$(CC) $(CFLAGS) -c src/main.c -o $(BIN)/main.o

Stack.o:src/Stack.c
	$(CC) $(CFLAGS) -c src/Stack.c -o $(BIN)/Stack.o

Tile.o:src/Tile.c
	$(CC) $(CFLAGS) -c src/Tile.c -o $(BIN)/Tile.o

Grid.o: src/Grid.c

	$(CC) $(CFLAGS) -c src/Grid.c -o $(BIN)/Grid.o

Player.o: src/Player.c

	$(CC) $(CFLAGS) -c src/Player.c -o $(BIN)/Player.o

Game.o: src/Game.c

	$(CC) $(CFLAGS) -c src/Game.c -o $(BIN)/Game.o
Meeple.o: src/Meeple.c
	$(CC) $(CFLAGS) -c src/Meeple.c -o $(BIN)/Meeple.o

clean:
	rm -f $(BIN)/*.o target

 