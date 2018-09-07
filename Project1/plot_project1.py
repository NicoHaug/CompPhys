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
filename1 = '/Users/Nicolai/Documents/Atom/CompPhys/Project1/results.txt'
x_num = np.loadtxt(filename1, usecols=0)
v1 = np.loadtxt(filename1, usecols=1)    # Algorithm A result
v2 = np.loadtxt(filename1, usecols=2)    # Algorithm B result

filename2 = '/Users/Nicolai/Documents/Atom/CompPhys/Project1/RelErr.txt'
h_err = np.loadtxt(filename2, usecols=0)
eps_err = np.loadtxt(filename2, usecols=1)


def plotB(n):
    plt.plot(x_exact, u(x_exact), label='Analytic')
    plt.plot(x_num, v1, label='A: Numerical with n=' + str(n) + ' gridpoints')
    plt.plot(x_num, v2, label='B: Numerical with n=' + str(n) + ' gridpoints')
    plt.gca().set_xlabel('$x$')
    plt.gca().set_ylabel('$u(x)$')
    plt.gca().set_title(
        'Analytic vs. Numerical Solution \n of the 1D Poisson Eq.')
    plt.legend(loc='best')
    plt.show()


# plotB(100)  # n = 10, 100, 1000

def plot_err():
    plt.plot(np.log10(h_err), eps_err)
    plt.xlabel('h')
    plt.ylabel('eps')
    plt.show()


plot_err()
