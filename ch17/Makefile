## A simple makefile
# use:
# make PROG=%e
# in geany
# I need to get better at dealing with multiple source files
#
CXX = g++
CXXFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++
BINDIR = ../bin
OBJDIR = ../obj
SRC = link_a
PROG = filename

$(PROG): $(OBJDIR)/$(PROG).o $(OBJDIR)/$(SRC).o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(PROG) $(OBJDIR)/$(PROG).o $(OBJDIR)/$(SRC).o

$(OBJDIR)/$(PROG).o: $(PROG).cpp
	$(CXX) $(CXXFLAGS) -c $(PROG).cpp -o $(OBJDIR)/$(PROG).o

$(OBJDIR)/$(SRC).o: $(SRC).hpp $(SRC).cpp
	$(CXX) $(CXXFLAGS) -c $(SRC).cpp -o $(OBJDIR)/$(SRC).o
