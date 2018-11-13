#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np

k = 1
T = 1
L = 2
beta = 1 / (k * T)

Ei = np.array([-8, -4, 0, 4, 8])
Z = np.sum(np.exp(-beta * Ei))
Emean = 1 / Z * np.sum(Ei * np.exp(-beta * Ei))

Mi = np.array([8, 4, 0, -4, -8])
Mmean = 1 / Z * np.sum(np.abs(Mi) * np.exp(-beta * Ei))
print("Mean energy: {}".format(Emean / L**2))
print("Mean magnetic moment: {}".format(Mmean / L**2))
