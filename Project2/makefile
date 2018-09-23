CPPflags = g++ -O3

LIB = -DARMA_DONT_USE_WRAPPER -lblas -llapack

main: main.o eigvalSolver.o
	${CPPflags} -o main.o main.cpp eigvalSolver.cpp ${LIB}

#test: test.o func.o
#	${CPPflags} -o test.o test.cpp func.cpp ${LIB}

#benchmark: benchmark.o func.o
#	${CPPflags} -o benchmark.o benchmark.cpp func.cpp ${LIB}
