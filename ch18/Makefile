## A simple makefile
# use:
# make PROG=%e
# in geany
CC = g++
CFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++
BINDIR = ~/swdev/c++/ppp/bin
OBJDIR = ../obj
PROG = filename

$(PROG): $(OBJDIR)/$(PROG).o
	$(CC) $(CFLAGS) -o $(BINDIR)/$(PROG) $(OBJDIR)/$(PROG).o

$(OBJDIR)/$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) -c $(PROG).cpp -o $(OBJDIR)/$(PROG).o
