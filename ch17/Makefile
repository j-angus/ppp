## A simple makefile
# use:
# make PROG=%e
# in geany
CC = g++
CFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++
BINDIR = ~/swdev/c++/ppp/bin
OBJDIR = ../obj
SRC = link_a
PROG = filename

$(PROG): $(OBJDIR)/$(PROG).o $(OBJDIR)/$(SRC).o
	$(CC) $(CFLAGS) -o $(BINDIR)/$(PROG) $(OBJDIR)/$(PROG).o $(OBJDIR)/$(SRC).o

$(OBJDIR)/$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) -c $(PROG).cpp -o $(OBJDIR)/$(PROG).o

$(OBJDIR)/$(SRC).o: $(SRC).hpp $(SRC).cpp
	$(CC) $(CFLAGS) -c $(SRC).cpp -o $(OBJDIR)/$(SRC).o
