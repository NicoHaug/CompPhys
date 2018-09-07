#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

# Set fontsizes in figures
params = {'legend.fontsize': 'large',
          'axes.labelsize': 'large',
          'axes.titlesize': 'large',
          'xtick.labelsize': 'large',
          'ytick.labelsize': 'large'}
plt.rcParams.update(params)


def u(x):
    '''Closed form solution'''
    return 1 - (1 - np.exp(-10)) * x - np.exp(-10 * x)


x_exact = np.linspace(0, 1, 10000)
filename1 = '/Users/Nicolai/Documents/Atom/CompPhys/Project1/result1.txt'
x_num = np.loadtxt(filename1, usecols=0)
v1 = np.loadtxt(filename1, usecols=1)    # Algorithm A result


def plotB(n):
    plt.plot(x_exact, u(x_exact), label='Analytic')
    plt.plot(x_num, v1, label='Numerical with n=' + str(n) + ' gridpoints')
    plt.gca().set_xlabel('$x$')
    plt.gca().set_ylabel('$u(x)$')
    plt.gca().set_title(
        'Analytic vs. Numerical Solution \n of the 1D Poisson Eq.')
    plt.legend(loc='best')
    plt.show()


plotB(10)  # n = 10, 100, 1000
