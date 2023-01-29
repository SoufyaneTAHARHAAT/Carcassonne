CC = gcc
CFLAGS = -Wall -Wextra  -pedantic -std=c11 -g
LDFLAGS = -lm
BIN = bin

target: main.o 
	$(CC) $(BIN)/main.o  -o $(BIN)/output $(LDFLAGS)

run: 
	$(BIN)/./output
debug:
	valgrind -s --track-origins=yes --leak-check=full $(BIN)/./output

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c -o ./$(BIN)/main.o

clean:
	rm -f $(BIN)/*.o target

 