#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import numpy.polynomial.polynomial as poly
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from scipy import stats
import sys

# Set fontsizes in figures
params = {'legend.fontsize': 'large',
          'axes.labelsize': 'large',
          'axes.titlesize': 'large',
          'xtick.labelsize': 'large',
          'ytick.labelsize': 'large'}
plt.rcParams.update(params)


def curvefit(x, y, deg=1):
    coefs = poly.polyfit(x, y, deg)
    ffit = poly.Polynomial(coefs)    # instead of np.poly1d
    slope = coefs[1]
    return ffit, slope


if sys.argv[1] == "pos":
    file = "./Raw_Data/data.txt"

    x = np.loadtxt(file, usecols=0)
    y = np.loadtxt(file, usecols=1)

    fig = plt.figure()
    plt.gca().set_aspect("equal")
    plt.plot(x, y)
    plt.gca().set_xlabel('$X$ [AU]')
    plt.gca().set_ylabel('$Y$ [AU]')
    plt.show()

if sys.argv[1] == "benchmark":
    file = "./Raw_Data/benchmark.txt"
    N = np.log10(np.loadtxt(file, usecols=0))
    T_euler = np.log10(np.loadtxt(file, usecols=1))
    T_verlet = np.log10(np.loadtxt(file, usecols=2))
    # fit1, slope1 = curvefit(N, T_euler, 1)
    # fit2, slope2 = curvefit(N, T_verlet, 1)
    slope1, intercept1, r_value1, p_value1, std_err1 = stats.linregress(
        N, T_euler)
    slope2, intercept2, r_value2, p_value2, std_err2 = stats.linregress(
        N, T_verlet)

    fig = plt.figure()
    plt.plot(N, T_euler, 'o:', label="Euler's Method")
    #plt.plot(N, fit1(N), "-", lw=2, label='Slope: ' + str(slope1))
    plt.plot(N, intercept1 + slope1 * N, '-',
             label='Euler fitted line. Slope: ' + str(round(slope1, 4)))
    plt.plot(N, T_verlet, 'o:', label="Verlet's Method")
    plt.plot(N, intercept2 + slope2 * N, '-',
             label='Verlet fitted line. Slope: ' + str(round(slope2, 4)))
    #plt.plot(N, fit2(N), "-", lw=2, label='Slope: ' + str(slope2))
    plt.gca().set_xlabel('$\\log_{10}(N)$')
    plt.gca().set_ylabel('$\\log_{10}(T)$')
    plt.legend(loc='best')
    plt.grid(True)
    plt.show()

if sys.argv[1] == "energy":
    file = "./Raw_Data/energy.txt"

    x = np.loadtxt(file, usecols=0)
    y = np.loadtxt(file, usecols=1)

    fig = plt.figure()
    plt.plot(np.linspace(0, 1, len(x)), x)
    plt.plot(np.linspace(0, 1, len(y)), y)
    plt.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
    plt.gca().set_xlabel('$x-axis$')
    plt.gca().set_ylabel('$E$')
    plt.grid(True)
    plt.show()

if sys.argv[1] == "fluctuation":
    file = "./Raw_Data/fluctuation.txt"
    label_ = sys.argv[2]

    n = np.loadtxt(file, usecols=0)
    y = np.loadtxt(file, usecols=1)

    fig = plt.figure()
    plt.plot(np.log10(n), np.log10(y), label=label_)
    plt.gca().set_xlabel('$\\log_{10}(N)$')
    plt.gca().set_ylabel('$\\log_{10}(E_f)$')
    plt.grid(True)
    plt.show()


if sys.argv[1] == "all":
    file = "./Raw_Data/data.txt"

    pos_sun = np.loadtxt(file, usecols=(0, 1, 2))
    pos_mercury = np.loadtxt(file, usecols=(3, 4, 5))
    pos_venus = np.loadtxt(file, usecols=(6, 7, 8))
    pos_earth = np.loadtxt(file, usecols=(9, 10, 11))
    pos_mars = np.loadtxt(file, usecols=(12, 13, 14))
    pos_jupiter = np.loadtxt(file, usecols=(15, 16, 17))
    pos_saturn = np.loadtxt(file, usecols=(18, 19, 20))
    pos_uranus = np.loadtxt(file, usecols=(21, 22, 23))
    pos_neptune = np.loadtxt(file, usecols=(24, 25, 26))
    pos_pluto = np.loadtxt(file, usecols=(27, 28, 29))

    # 2D plot

    plt.figure()
    plt.gca().set_aspect("equal")
    # plt.style.use('dark_background')
    plt.grid(False)
    plt.plot(pos_sun[:, 0], pos_sun[:, 1],
             'yo', label='Sun', markersize=5)
    plt.plot(pos_mercury[:, 0], pos_mercury[:, 1],
             color='darkslategrey', label='Mercury')
    plt.plot(pos_venus[:, 0], pos_venus[:, 1],
             color='tan', label='Venus')
    plt.plot(pos_earth[:, 0], pos_earth[:, 1],
             color='deepskyblue', label='Earth')
    plt.plot(pos_mars[:, 0], pos_mars[:, 1],
             color='tomato', label='Mars')
    plt.plot(pos_jupiter[:, 0], pos_jupiter[:, 1],
             color='orange', label='Jupiter')
    plt.plot(pos_saturn[:, 0], pos_saturn[:, 1],
             color='olive', label='Saturn')
    plt.plot(pos_uranus[:, 0], pos_uranus[:, 1],
             color='darkviolet', label='Uranus')
    plt.plot(pos_neptune[:, 0], pos_neptune[:, 1],
             color='darkblue', label='Neptune')
    plt.plot(pos_pluto[:, 0], pos_pluto[:, 1],
             color='black', label='Pluto')

    plt.subplots_adjust(right=0.68)
    plt.legend(loc='center left', bbox_to_anchor=(1.04, 0.5),
               fancybox=True, borderaxespad=0, ncol=1)
    plt.show()

    # 3D plot
    plt.figure()
    plt.gcf().add_subplot(111, projection='3d')
    plt.gca().set_aspect("equal")
    # plt.style.use('dark_background')
    plt.grid(False)
    plt.plot(pos_sun[:, 0], pos_sun[:, 1],
             pos_sun[:, 2], 'yo', label='Sun', markersize=5)
    plt.plot(pos_mercury[:, 0], pos_mercury[:, 1],
             pos_mercury[:, 2], color='darkslategrey', label='Mercury')
    plt.plot(pos_venus[:, 0], pos_venus[:, 1],
             pos_venus[:, 2], color='tan', label='Venus')
    plt.plot(pos_earth[:, 0], pos_earth[:, 1],
             pos_earth[:, 2], color='deepskyblue', label='Earth')
    plt.plot(pos_mars[:, 0], pos_mars[:, 1],
             pos_mars[:, 2], color='tomato', label='Mars')
    plt.plot(pos_jupiter[:, 0], pos_jupiter[:, 1],
             pos_jupiter[:, 2], color='orange', label='Jupiter')
    plt.plot(pos_saturn[:, 0], pos_saturn[:, 1],
             pos_saturn[:, 2], color='olive', label='Saturn')
    plt.plot(pos_uranus[:, 0], pos_uranus[:, 1],
             pos_uranus[:, 2], color='darkviolet', label='Uranus')
    plt.plot(pos_neptune[:, 0], pos_neptune[:, 1],
             pos_neptune[:, 2], color='darkblue', label='Neptune')
    plt.plot(pos_pluto[:, 0], pos_pluto[:, 1],
             pos_pluto[:, 2], color='black', label='Pluto')

    plt.gca().set_xlim(-30, 30)
    plt.gca().set_ylim(-30, 30)
    plt.gca().set_zlim(-5, 5)
    plt.subplots_adjust(right=0.68)
    plt.legend(loc='center left', bbox_to_anchor=(1.04, 0.5),
               fancybox=True, borderaxespad=0, ncol=1)
    plt.show()
