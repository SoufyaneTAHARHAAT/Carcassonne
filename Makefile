CC = gcc
CFLAGS = -Wall -Wextra	
INC = include/


EXEC = test carcassone 
test: carcassone
	./carcassone
carcassone: 
	gcc  $(CFLAGS) src/game.c src/carcassone.c  -o ./bin/carcassone

clean:
	rm ${BIN}*