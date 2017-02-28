SRCDIR = ./src/
BINDIR = ./bin/
LIBS = -ledit
CFLAGS = -std=c99 -Wall -I ./src/

all:
	gcc $(SRCDIR)flappy.c $(SRCDIR)flappy-help.c $(LIBS) $(CFLAGS) -o $(BINDIR)flappy

clean:
	rm ./bin/*
