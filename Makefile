CC = gcc
CFLAGS = -Wall -Wextra  -pedantic -std=c11 -g
LDFLAGS = -lm
BIN = bin

target: main.o Stack.o Tile.o Grid.o
	$(CC) $(BIN)/main.o $(BIN)/Stack.o $(BIN)/Tile.o ${BIN}/Grid.o  -o $(BIN)/out $(LDFLAGS)

run: 
	$(BIN)/./out
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

clean:
	rm -f $(BIN)/*.o target

 