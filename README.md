# FYS3150 Computational Physics I

Repository for projects in FYS3150.

### Project 1

[Project 1](https://github.com/nicolossus/FYS3150/tree/master/Project1) explores three different numerical algorithms for solving the one-dimensional Poisson equation recast as a tridiagonal matrix by discretization. The first algorithm, labeled “General Algorithm”, use the Gaussian elimination procedure and backward substitution as described by the Thomas algorithm. The second algorithm, labeled “Optimized Algorithm”, is an optimalization of the General Algorithm by specializing it to the specific matrix spawned by the discretization of the Poisson equation. The third algorithm, labeled “LU-decomposition Algorithm” use the built-in LU-decomposition procedure in the C++ library Armadillo. The subject of particular interest in this project is the computational performance of the algorithms.
