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

TARGETS = main.x allPlanets.x test.x

all: $(TARGETS)

main.x: main.o $(OBJS)
	${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

main.o: main.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

allPlanets.x: allPlanets.o $(OBJS)
	${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}

allPlanets.o: allPlanets.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

solver.o: solver.h
	${CXX} ${CPPflags} -c solver.cpp ${INCL} ${LIB}

planet.o: planet.h
	${CXX} ${CPPflags} -c planet.cpp ${INCL} ${LIB}

test.x: test.o $(OBJS)
		${CXX} ${CPPflags} -o $@ $^ ${INCL} ${LIB}
		./test.x

test.o: test.cpp
	${CXX} ${CPPflags} -c $^ ${INCL} ${LIB}

clean:
	rm -f *.o *.txt *.x



	CPPflags = g++ -O3

	LIB = -DARMA_DONT_USE_WRAPPER -lblas -llapack

	main.x: main.o planet.o solver.o
		${CPPflags} -o main.x main.cpp planet.cpp solver.cpp ${LIB}

	allPlanets.x: allPlanets.o planet.o solver.o
		${CPPflags} -o allPlanets.x allPlanets.cpp planet.cpp solver.cpp ${LIB}

	test: test.o planet.o solver.o
		${CPPflags} -o test.x test.cpp planet.cpp solver.cpp ${LIB}
		./test.x

	clean:
		rm -f *.o *.txt *.x
