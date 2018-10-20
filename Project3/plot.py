import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import sys

# Set fontsizes in figures
params = {'legend.fontsize': 'large',
          'axes.labelsize': 'large',
          'axes.titlesize': 'large',
          'xtick.labelsize': 'large',
          'ytick.labelsize': 'large'}
plt.rcParams.update(params)

if sys.argv[1] == "pos":
    file = "data.txt"

    x = np.loadtxt(file, usecols=0)
    y = np.loadtxt(file, usecols=1)

    fig = plt.figure()
    # plt.gca().set_aspect("equal")
    plt.plot(x, y)
    plt.show()

if sys.argv[1] == "energy":
    file = "energy.txt"

    x = np.loadtxt(file, usecols=0)
    y = np.loadtxt(file, usecols=1)

    fig = plt.figure()
    # plt.gca().set_aspect("equal")
    plt.plot(np.linspace(0, 1, len(x)), x)
    plt.plot(np.linspace(0, 1, len(y)), y)
    plt.grid(True)
    plt.show()

if sys.argv[1] == "fluctuation":
    file = "fluctuation.txt"

    n = np.loadtxt(file, usecols=0)
    y = np.loadtxt(file, usecols=1)

    fig = plt.figure()
    plt.plot(np.log10(n), np.log10(y))
    plt.grid(True)
    plt.show()


if sys.argv[1] == "all":
    file = "data.txt"

    pos_sun = np.loadtxt(file, usecols=(0, 1, 2))
    pos_mercury = np.loadtxt(file, usecols=(3, 4, 5))
    pos_venus = np.loadtxt(file, usecols=(6, 7, 8))
    pos_earth = np.loadtxt(file, usecols=(9, 10, 11))
    pos_mars = np.loadtxt(file, usecols=(12, 13, 14))
    pos_jupiter = np.loadtxt(file, usecols=(15, 16, 17))
    pos_saturn = np.loadtxt(file, usecols=(18, 19, 20))
    pos_uranus = np.loadtxt(file, usecols=(21, 21, 23))
    pos_neptune = np.loadtxt(file, usecols=(24, 25, 26))
    pos_pluto = np.loadtxt(file, usecols=(27, 28, 29))

    # 2D plot
    plt.figure()
    plt.plot(pos_sun[:, 0], pos_sun[:, 1], label='Sun')
    plt.plot(pos_earth[:, 0], pos_earth[:, 1], label='Earth')
    # plt.plot([:, 0], v[:, 1], v[:, 2])
    plt.legend(loc='best')
    plt.show()

    # 3D plot
    plt.figure()
    plt.gcf().add_subplot(111, projection='3d')
    plt.gca().set_aspect("auto")
    plt.plot(pos_sun[:, 0], pos_sun[:, 1], pos_sun[:, 2], label='Sun')
    #plt.plot(pos_mercury[:, 0], pos_mercury[:, 1], pos_mercury[:, 2])
    #plt.plot(pos_venus[:, 0], pos_venus[:, 1], pos_venus[:, 2])
    plt.plot(pos_earth[:, 0], pos_earth[:, 1], pos_earth[:, 2], label='Earth')
    # plt.plot([:, 0], v[:, 1], v[:, 2])
    plt.legend(loc='best')
    plt.show()


"""
x1 = np.loadtxt(file, usecols=0)
y1 = np.loadtxt(file, usecols=1)
x2 = np.loadtxt(file, usecols=6)
y2 = np.loadtxt(file, usecols=7)
#x3 = np.loadtxt(file, usecols=12)
#y3 = np.loadtxt(file, usecols=13)
plt.plot(x1, y1)
plt.plot(x2, y2)
#plt.plot(x3, y3)
plt.show()
"""
