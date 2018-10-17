CC = gcc
CXX = g++
CPPflags = -g -Wall -std=c++11 -O3

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
INCL := -I /usr/local/Cellar/armadillo/9.100.5/include
LIB := -DARMA_DONT_USE_WRAPPER -framework Accelerate
endif

ifeq ($(UNAME), Linux)
INCL :=
LIB := -DARMA_DONT_USE_WRAPPER -lblas -llapack
endif

OBJS = ODEint.o SolarSystem.o

TARGETS = main.x twoBody.x test.x

all: $(TARGETS)

main.x: main.o $(OBJS)
	${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

main.o: main.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

SolarSystem.o: SolarSystem.hpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

ODEint.o: ODEint.hpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

test.x: test.o $(OBJS)
		${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}
		./test.x

test.o: test.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

clean:
	rm -f *.o *.txt *.x
