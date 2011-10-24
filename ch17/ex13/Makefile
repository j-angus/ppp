## A simple makefile
# use:
# make PROG=%e
# in geany
# I need to get better at dealing with multiple source files
# I believe all the implicit rule type stuff works better if Makefile
# is stored in the bin directory...
# Check out some open source projects to see how files and Makefile
# are arranged.
#vpath %.o ../../obj
#GPATH = ../../obj
CXX = g++
CXXFLAGS = -gdwarf-2 -Wall -Wextra -Weffc++

# experiment putting compiled binaries and objects into one file below sources
BINDIR = ../bin
OBJDIR = ../obj
PROG = ch17ex13
#SRCDIR = ../
SRC = link
objects = $(OBJDIR)/$(PROG).o $(OBJDIR)/$(SRC).o

$(PROG) : $(objects)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(PROG) $(objects)

$(OBJDIR)/$(PROG).o : $(PROG).cpp
	$(CXX) $(CXXFLAGS) -c $(PROG).cpp -o $(OBJDIR)/$(PROG).o

$(OBJDIR)/$(SRC).o : $(SRC).h $(SRC).cpp
	$(CXX) $(CXXFLAGS) -c $(SRC).cpp -o $(OBJDIR)/$(SRC).o

.PHONY : clean
clean :
	-rm $(PROG) $(objects)

