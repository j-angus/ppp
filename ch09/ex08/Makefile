## A simple makefile
# use:
# make PROG=%e
# in geany

CC = g++
CFLAGS = -g -Wall -Wextra -Weffc++
BINDIR = ~/swdev/c++/ppp/bin
PROG = filename
SRC = patron

$(PROG): $(PROG).o $(SRC).o
	$(CC) $(CFLAGS) -o $(BINDIR)/$(PROG) $(PROG).o $(SRC).o

$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) -c $(PROG).cpp

$(SRC).o: $(SRC).cpp $(SRC).hpp
	$(CC) $(CFLAGS) -c $(SRC).cpp
