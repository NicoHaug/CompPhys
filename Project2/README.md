# Project 2

This repository contains programs made for project 2 produced in a collaboration between [Lasse](https://github.com/lasselb87), [Nicolai](https://github.com/nicolossus), and [Kristian](https://github.com/KristianWold).

### Contents

**Eigenvalue Solver**

[jacobi.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/jacobi.cpp) contains an eigenvalue solver which use the Jacobi rotation method, and have the accompanying header file [jacobi.h](https://github.com/nicolossus/FYS3150/blob/master/Project2/jacobi.h).

***Function prototype***
```cpp
//============================================================================
int jacobiMethod(mat A, vec &eigval, mat &eigvec, int N);
//----------------------------------------------------------------------------
// Diagonalize A and generate a sorted set of eigenvalues and eigenvectors
//
// Input:
// A - matrix to be diagonalized
// eigval - address to put eigenvalues
// eigvec - address to put eigenvectors
// N - dimension of matrix
//
// Return:
// number of similarity transformations
//----------------------------------------------------------------------------
```

***Usage***
```cpp
#include "jacobi.h"
int main()
{
  int N = foo;          // Number of mesh points
  mat A = foo;          // Real symmetric (NxN) matrix
  int n;                // Number of similarity transformations
  vec eigval;           // Declare eigval for storing eigenvalues
  mat eigvec;           // Declare eigvec for storing eigenvectors
  n = jacobiMethod(A, eigval, eigvec, N);
  return 0;
}
```

**Solved Problems**

[bucklingBeam.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/bucklingBeam.cpp) contains the code for solving the buckling beam problem using the Jacobi rotation method. Compile with `make bucklingBeam` and run with `./bucklingBeam.x`

[quantumDot.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/quantumDot.cpp) contains the code for finding the ground state eigenvalue and the first three excited state eigenvalues for electrons in a harmonic oscillator well using the Jacobi rotation method. Compile with `make quantumDot` and run with `./quantumDot.x`

[waveFunctions.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/waveFunctions.cpp) contains the code for calculating the wave functions of the interacting and non-interacting case of two electrons in a harmonic oscillator potential for a given oscillator frequency. Compile with `make waveFunctions` and run with `./waveFunctions.x`. Running the program produces a plot of the wave functions with the specified parameters, located in the [Results folder](https://github.com/nicolossus/FYS3150/tree/master/Project2/Results).

[test.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/test.cpp) contains code for three unit tests, checking that the Jacobi method is correctly implemented. Compile and run with `make test`

[benchmark.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/test.cpp) contains code that checks the performance of Jacobi's method and Armadillo's eig_sym(). Compile and run with `make benchmark`. This produces two plots. The first is a log-log plot of CPU-time vs dimension for the two methods. The second produces a log-log plot of the number of similarity transformations Jacobi's method need to perform.

[plot.py](https://github.com/nicolossus/FYS3150/blob/master/Project2/plot.py) contains code for visualizing the data, and is called by the makefile.

[makefile](https://github.com/nicolossus/FYS3150/blob/master/Project2/makefile) see descriptions above. To clean directory for object files and executables, run `make clean`. Run `make cleanResults` to clean the [Results folder](https://github.com/nicolossus/FYS3150/tree/master/Project2/Results) for all text files and figures.

All data produced in this project can be found in the [Results folder](https://github.com/nicolossus/FYS3150/tree/master/Project2/Results)
