
CPPflags = g++ -std=c++11 -O3

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
INCLUDES = -I /usr/local/Cellar/armadillo/9.100.5/include
LIB = -DARMA_DONT_USE_WRAPPER -framework Accelerate
endif

ifeq ($(UNAME), Linux)
LIB = -DARMA_DONT_USE_WRAPPER -lblas -llapack
endif


bucklingBeam: bucklingBeam.o jacobi.o
	${CPPflags} -o bucklingBeam.x bucklingBeam.cpp jacobi.cpp ${LIB}

quantumDot: quantumDot.o jacobi.o
	${CPPflags} -o quantumDot.x quantumDot.cpp jacobi.cpp ${LIB}

benchmark: benchmark.o jacobi.o
	${CPPflags} -o benchmark.x benchmark.cpp jacobi.cpp ${LIB}
	./benchmark.x
	python plot.py benchmark

clean:
	rm -f *.o *.txt *.x
