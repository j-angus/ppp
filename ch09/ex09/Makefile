## A simple makefile
# use:
# make PROG=%e
# in geany

CC = g++
CFLAGS = -g -Wall -Wextra -Weffc++
LDFLAGS = -lboost_date_time
BINDIR = ~/swdev/c++/ppp/bin
PROG = ch09ex09
# SRC = Patron

$(PROG): $(PROG).o Book.o Patron.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(PROG) $(PROG).o Book.o Patron.o

$(PROG).o: $(PROG).cpp Book.h Patron.h
	$(CC) $(CFLAGS) -c $(PROG).cpp

Book.o: Book.cpp Book.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c Book.cpp

Patron.o: Patron.cpp Patron.h
	$(CC) $(CFLAGS) -c Patron.cpp
