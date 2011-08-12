## A makefile for compiling FLTK prorams from Stroustrup's
# Programming Principles and Practice Using C++
# use:
# make PROG=%e
# in geany
CC = g++
# compiler flags
CFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++
# linker flags
LDFLAGS = -lfltk -lfltk_forms -lfltk_images -lXext -lX11 -lm
BINDIR = ~/swdev/c++/ppp/bin
PROG = filename

$(PROG): $(PROG).o Graph.o GUI.o Simple_window.o Window.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(PROG) $(PROG).o Graph.o GUI.o Simple_window.o Window.o

$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(PROG).cpp

Graph.o: Graph.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c Graph.cpp

GUI.o: GUI.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c GUI.cpp

Simple_window.o: Simple_window.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c Simple_window.cpp

Window.o: Window.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c Window.cpp