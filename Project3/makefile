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

OBJS = planet.o solver.o
TARGET1 = main.x
TARGET2 = allPlanets.x
TARGET3 = test.x
TARGETS = $(TARGET1) $(TARGET2) $(TARGET3)

all: $(TARGETS)

main: $(TARGET1)

allPlanets: $(TARGET2)

test: $(TARGET3)

main.x: main.o $(OBJS)
	${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

main.o: main.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

allPlanets.x: allPlanets.o $(OBJS)
	${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

allPlanets.o: allPlanets.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

solver.o:
	${CXX} ${CPPflags} -c solver.cpp ${INCL} ${LIB}

planet.o:
	${CXX} ${CPPflags} -c planet.cpp ${INCL} ${LIB}

test.x: test.o $(OBJS)
		${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}
		./test.x
		rm -f test.o test.x

test.o: test.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

clean:
	rm -f *.o *.txt *.x
