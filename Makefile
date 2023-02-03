CC = gcc
CFLAGS = -Wall -Wextra  -pedantic -std=c11 -g
LDFLAGS = -lm
BIN = bin

target: main.o Stack.o
	$(CC) $(BIN)/main.o $(BIN)/Stack.o  -o $(BIN)/out $(LDFLAGS)

run: 
	$(BIN)/./out
debug:
	valgrind -s --track-origins=yes --leak-check=full $(BIN)/./out

main.o: src/main.c 
	$(CC) $(CFLAGS) -c src/main.c -o $(BIN)/main.o

Stack.o:src/Stack.c
	$(CC) $(CFLAGS) -c src/Stack.c -o $(BIN)/Stack.o

clean:
	rm -f $(BIN)/*.o target

 