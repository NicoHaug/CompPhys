# Project 2

This repository contains all finalized programs in project 2 produced in a collaboration between [Lasse](https://github.com/lasselb87), [Nicolai](https://github.com/nicolossus), and [Kristian](https://github.com/KristianWold).

### Contents

[jacobi.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/jacobi.cpp) contains an eigenpair solver which use the Jacobi method, and have the accompanying header file [jacobi.h](https://github.com/nicolossus/FYS3150/blob/master/Project2/jacobi.h)

[makefile](https://github.com/nicolossus/FYS3150/blob/master/Project2/makefile) commands:
"make bucklingBeam"
"make benchmark"

[quantumDot.cpp] is used to calculate the four lowest-lying energy states for electrons in a harmonic oscillator well, using Jacobi's method of diagonalization of a matrix. To compile, type "make quantumDot" into the commandline. Run then ./quantumDot.o to see what arguments to give.

[eigenvectors.cpp] is used to calculate the wavefunctions of the interacting and non-interacting case of two electrons for a given frequency. To compile, type "make eigenvectors". Run then ./quantumDot.o to see what arguments to give.

[test.cpp] runs three unit-test checking that the method is correctly implemented. Type "make test" to run it.

[benchmark.cpp] checks the performance of Jacobi's method and Armadillo's eig_sym(). Type "make benchmark" to run it. This produces
two plots. The first is a log-log plot of CPU-time vs dimmension for the two methods. The second produces a log-log plot of the number of iterations Jacobi's method needs to perform.

[plot.py] visualizes the data, and is called by the Makefile.

All data produced in this project can be found in the [Results folder](https://github.com/nicolossus/FYS3150/tree/master/Project1/Results)ENDRE!!!.
