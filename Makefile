CXX = g++
CXXFLAGS = -g3 -Wall

LIBS=-lm

dataloader.o: clean dataloader.cpp dataloader.h
	$(CXX) $(CXXFLAGS) -c dataloader.cpp

metrored.o: metrored.cpp dataloader.h
	$(CXX) $(CXXFLAGS) -c metrored.cpp

all: dataloader.o metrored.o 
	$(CXX) $(CXXFLAGS) -o programa main.cpp dataloader.o metrored.o

clean:
	rm -fr *.o a.out programa

.DEFAULT_GOAL := all