CXX = g++
CPPflags = -g -Wall -std=c++11 -O3

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
INCL := -I /usr/local/Cellar/armadillo/9.100.5/include
LIB += -DARMA_DONT_USE_WRAPPER -framework Accelerate
endif

ifeq ($(UNAME), Linux)
INCL :=
LIB := -DARMA_DONT_USE_WRAPPER -lblas -llapack
endif

OBJS = metropolis.o
TARGET1 = main.x

TARGETS = $(TARGET1)

.PHONY: all

all: $(TARGETS)

main.x: main.o $(OBJS)
	${CXX} -o $@ $^ 
	./main.x
	rm -f main.o main.x

main.o: main.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

metropolis.o:
	${CXX} ${CPPflags} -c ./Classes/metropolis.cpp ${INCL} ${LIB}

.PHONY: clean

clean:
	rm -f *.o *.txt *.x

cleanResults:
	rm -f ./Results/*.txt ./Results/*.png ./Results/*.pdf
