# Project 4

This repository contains programs made for project 4 produced in a collaboration between [Lasse](https://github.com/lasselb87), [Nicolai](https://github.com/nicolossus), and [Kristian](https://github.com/KristianWold).


### Contents

The [classes](https://github.com/nicolossus/FYS3150/tree/master/Project4/Classes) folder contains object-oriented code
for calculating Ising Model estimations using the Metropolis Algorithm.

The [Results](https://github.com/nicolossus/FYS3150/tree/master/Project4/Results) folder contains raw data results.

The [Plots](https://github.com/nicolossus/FYS3150/tree/master/Project4/Plots) folder contains all figures produced in this project.

**Usage**

To compile the C++ implementation of the Metropolis Algorithm, run `make simulation.x`.

To perform benchmarking, run `python evolution N 1000 2 1 3 0.01`, where N is the desired
number of MC cycles. Run then `python analyticalVsNumerical N` to produce the plot.

To produce the plots showing how the system moves toward equilibrium, run `python equilibrium.py`.

To produce the probability distribution, run `python distribution.py`.

To produce plots of the number of accepted states as a function of N and T, run `python acceptedStates.py`.

To produce the plots showing the phase transition and finite size scaling, run `python phaseTrans.py`.
