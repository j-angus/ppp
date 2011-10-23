## A simple makefile
# use:
# make PROG=%e
# in geany
CC = g++
CFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++
BINDIR = ../bin/
OBJDIR = ../obj/
PROG = ch18ex12
INC = cave
$(PROG): $(OBJDIR)$(PROG).o $(OBJDIR)$(INC).o
	$(CC) $(CFLAGS) -o $(BINDIR)$(PROG) $(OBJDIR)$(PROG).o $(OBJDIR)$(INC).o

$(OBJDIR)$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) -c $(PROG).cpp -o $(OBJDIR)$(PROG).o

$(OBJDIR)$(INC).o: $(INC).cpp $(INC).h
	$(CC) $(CFLAGS) -c $(INC).cpp -o $(OBJDIR)$(INC).o
