## A makefile for compiling FLTK prorams from Stroustrup's
# Programming Principles and Practice Using C++
# use:
# make PROG=%e
# in geany
# 'make clean'  removes all .o and executable files

CC = g++
CFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++
LDFLAGS = -lfltk -lfltk_forms -lfltk_images -lXext -lX11 -lm
BINDIR = ~/swdev/c++/ppp/bin
PROG = filename
OBJS = $(PROG).o Graph.o GUI.o Simple_window.o Window.o
SRCS =

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(PROG) $(OBJS)

$(PROG).o: $(PROG).cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(PROG).cpp

Graph.o: Graph.h Graph.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c Graph.cpp

GUI.o: GUI.h GUI.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c GUI.cpp

Simple_window.o: Simple_window.h Simple_window.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c Simple_window.cpp

Window.o: Window.h Window.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c Window.cpp

clean:
	rm core $(OBJS) $(BINDIR)/$(PROG)