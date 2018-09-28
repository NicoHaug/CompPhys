
import numpy as np
import matplotlib.pyplot as plt
import numpy.polynomial.polynomial as poly
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


if sys.argv[1] == "benchmark":
    file = "benchmark.txt"

    n = np.log10(np.loadtxt(file, usecols=0))
    t1 = np.log10(np.loadtxt(file, usecols=1))
    t2 = np.log10(np.loadtxt(file, usecols=2))
    iter = np.log10(np.loadtxt(file, usecols=3))

    fit1, slope1 = curvefit(n, t1)
    fit2, slope2 = curvefit(n, t2)
    fit3, slope3 = curvefit(n, iter)

    fig1 = plt.figure(1)
    title = "Jacobi's Method vs Armadillo's eig_sym()"

    plt.plot(n, t1, 'o-', label='Jacobi')
    plt.plot(n, fit1(n), ":", label=slope1)
    plt.plot(n, t2, 'o-', label='Armadillo')
    plt.plot(n, fit2(n), ":", label=slope2)

    plt.gca().set_xlabel('$\\log_{10}(n)$')
    plt.gca().set_ylabel('$\\log_{10}(t)$')
    plt.gca().set_title(title)
    plt.legend(loc='best')
    fig1.savefig("./Results/benchmark.png")

    fig2 = plt.figure(2)
    title = "Jacobi's Method\n Number of Iterations"
    plt.plot(n, iter, 'o-', label='Number of iterations')
    plt.plot(n, fit3(n), ":", lw=2, label='Slope: ' + str(slope3))

    plt.gca().set_xlabel('$\\log_{10}(n)$')
    plt.gca().set_ylabel('$\\log_{10}(N)$')
    plt.gca().set_title(title)
    plt.legend(loc='best')
    fig2.savefig("./Results/benchmark_iter.png")
