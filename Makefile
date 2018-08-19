CXX = g++
CXXFLAGS = -g3 -Wall

LIBS=-lm

Metro.o: clean Metro.cpp Metro.h
	$(CXX) $(CXXFLAGS) -c Metro.cpp

all: Metro.o
	$(CXX) $(CXXFLAGS) -o programa main.cpp Metro.o

clean:
	rm -fr *.o a.out programa

.DEFAULT_GOAL := all