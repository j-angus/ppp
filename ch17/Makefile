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

$(OBJDIR)/$(PROG).o: $(PROG).cc
	$(CXX) $(CXXFLAGS) -c $(PROG).cc -o $(OBJDIR)/$(PROG).o

$(OBJDIR)/$(SRC).o: $(SRC).h $(SRC).cc
	$(CXX) $(CXXFLAGS) -c $(SRC).cc -o $(OBJDIR)/$(SRC).o
