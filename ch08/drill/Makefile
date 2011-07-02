# Which compiler
CC = g++
# Where are include files kept
INCLUDE = .
# Options for development
CFLAGS = -g -Wall

use: use.o my.o
	$(CC) -o use use.o my.o
my.o: my.cpp my.h ../../std_lib_facilities.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c my.cpp
use.o: use.cpp my.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c use.cpp
