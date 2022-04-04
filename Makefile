# Makefile: TicTacWowWeeWow

# macro definitions
CC = gcc
DEBUG = -g
CFLAGS = -Wall -ansi -std=c99 $(DEBUG) -c
LFLAGS = -Wall $(DEBUG)

# dummy targets
all: TicTacWowWeeWow

clean:
	rm -f *.o
	rm -f Player
	rm -f Node
	rm -f TicTacWowWeeWow.txt

#compilation rules

Settings.o: Settings.c Settings.h
	$(CC) $(CFLAGS) Settings.c -o Settings.o

Game.o: Game.c Game.h Settings.h
	$(CC) $(CFLAGS) Game.c -o Game.o

AI.o: AI.c AI.h Game.h Settings.h
	$(CC) $(CFLAGS) AI.c -o AI.o

TicTacWowWeeWow.o: TicTacWowWeeWow.c Game.h Settings.h AI.h
	$(CC) $(CFLAGS) TicTacWowWeeWow.c -o TicTacWowWeeWow.o

TicTacWowWeeWow: Game.o Settings.o AI.o TicTacWowWeeWow.o
	$(CC) $(LFLAGS) Settings.o Game.o AI.o TicTacWowWeeWow.o -o TicTacWowWeeWow

#EOF
