CC = gcc
CFLAGS = -Wall -Wextra  -pedantic -std=c11 -g
LDFLAGS = -lm
BIN = bin

target: main.o Stack.o Tile.o Grid.o Game.o Player.o Meeple.o Grid_Validator.o Open_squares.o
	$(CC) $(BIN)/main.o $(BIN)/Stack.o $(BIN)/Tile.o $(BIN)/Grid.o $(BIN)/Player.o $(BIN)/Meeple.o $(BIN)/Game.o $(BIN)/Grid_Validator.o $(BIN)/Open_squares.o -o $(BIN)/exe $(LDFLAGS)

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

Grid_Validator.o: src/Validators/Grid_Validator.c
	$(CC) $(CFLAGS) -c src/Validators/Grid_Validator.c -o $(BIN)/Grid_Validator.o

Open_squares.o: src/Open_squares.c
	$(CC) $(CFLAGS) -c src/Open_squares.c -o $(BIN)/Open_squares.o
clean:
	rm -f $(BIN)/*.o target

 