# Project 5

This repository contains programs made for project 5 produced in a collaboration between [Lasse](https://github.com/lasselb87), [Nicolai](https://github.com/nicolossus), and [Kristian](https://github.com/KristianWold).

In this project we use the variational Monte Carlo method to evaluate the ground state energy, the relative distance between two electrons and expectation value of the kinetic and potential energies of a quantum dot with N = 2 electrons in three dimensions.

### Contents

- [main.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/main.cpp): main program. Run all simulations in this project.

- [plot.py](https://github.com/nicolossus/FYS3150/blob/master/Project5/plot.cpp): plotting procedures.

The [classes](https://github.com/nicolossus/FYS3150/tree/master/Project5/classes) folder contains:

- [VMC.hpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/classes/VMC.hpp): class framework for the variational Monte Carlo method and the Metropolis algorithm.

- [VMC.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/classes/VMC.cpp): member functions of the VMC class.

- [catch.hpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/classes/catch.hpp): test framework for unit-tests, retrieved from the GitHub repository [catchorg/Catch2](https://github.com/catchorg/Catch2).

- [test.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/classes/test.cpp): unit tests for verifying the VMC class.

- [wavefunctions.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/classes/wavefunctions.cpp): trial wave functions used by both [test.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/classes/test.cpp) and [main.cpp](https://github.com/nicolossus/FYS3150/blob/master/Project5/main.cpp)

The [results](https://github.com/nicolossus/FYS3150/tree/master/Project5/results) folder contains all the raw results produced in this project.

The [plots](https://github.com/nicolossus/FYS3150/tree/master/Project5/plots) folder contains all the plots produced in this project.

**Usage**

To compile and reproduce all results run `python3 automation.py`
