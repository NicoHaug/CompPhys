#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
This program contains plotting procedures for producing the results in
this project
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
import sys

# Set fontsizes in figures
params = {'legend.fontsize': 'x-large',
          'axes.labelsize': 'x-large',
          'axes.titlesize': 'x-large',
          'xtick.labelsize': 'x-large',
          'ytick.labelsize': 'x-large'}
plt.rcParams.update(params)


def linregress(x, y):
    slope, intercept, r_value, p_value, std_err = stats.linregress(
        x, y)
    fit = intercept + slope * x
    return fit, slope
