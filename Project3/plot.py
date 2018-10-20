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
