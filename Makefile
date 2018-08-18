CXX = g++
CXXFLAGS = -g3 -Wall

LIBS=-lm

funciones.o: clean funciones.cpp funciones.h
	$(CXX) $(CXXFLAGS) -c funciones.cpp

all: funciones.o
	$(CXX) $(CXXFLAGS) -o programa main.cpp funciones.o

clean:
	rm -fr *.o a.out programa

.DEFAULT_GOAL := all