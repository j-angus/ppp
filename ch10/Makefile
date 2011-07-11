## A simple makefile
# use:
# make PROG=%e
# in geany
CC = g++
CFLAGS = -g -Wall -Wextra -Weffc++
BINDIR = ~/swdev/c++/ppp/bin
PROG = filename

$(PROG): $(PROG).o
	$(CC) $(CFLAGS) -o $(BINDIR)/fw $(PROG).o

$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) -c $(PROG).cpp
