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
BINDIR = ../../bin
OBJDIR = ../../obj
objects = $(OBJDIR)/ch17ex11_a.o $(OBJDIR)/link_a.o
#SRC = 
PROG = ch17ex11_a

$(PROG) : $(objects)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(PROG) $(objects)

$(OBJDIR)/$(PROG).o : $(PROG).cc
	$(CXX) $(CXXFLAGS) -c $(PROG).cc -o $(OBJDIR)/$(PROG).o

$(OBJDIR)/link_a.o : link_a.h link_a.cc
	$(CXX) $(CXXFLAGS) -c link_a.cc -o $(OBJDIR)/link_a.o

.PHONY : clean
clean :
	-rm $(BINDIR)/$(PROG) $(objects)

