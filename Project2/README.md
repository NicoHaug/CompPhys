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
  mat A = foo;          // Real symmetric matrix
  int n;                // Number of similarity transformations
  vec eigval;           // Declare eigval for storing eigenvalues
  mat eigvec;           // Declare eigvec for storing eigenvectors
  n = jacobiMethod(A, eigval, eigvec, N);
  return 0;
}
```

**Solved Problems**

[bucklingBeam.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/bucklingBeam.cpp) contains the code for solving the buckling beam problem using the Jacobi rotation method. Compile with `make bucklingBeam`, and run with `./bucklingBeam.x`

[quantumDot.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project2/quantumDot.cpp) contains the code for finding the ground state eigenvalue and the first three excited state eigenvalues for electrons in a harmonic oscillator well using the Jacobi rotation method. Compile with `make quantumDot`, and run with `./quantumDot.x`
