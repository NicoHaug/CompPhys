#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np

print("Gen, n=10e1, time=", np.mean(
    np.array([1.1887e-5, 1.1367e-5, 1.1405e-5, 1.1486e-5, 1.1574e-5])))
print("Opt, n=10e1, time=", np.mean(
    np.array([3.64e-7, 3.82e-7, 4.39e-7, 3.85e-7, 3.71e-7])))
print("LUd, n=10e1, time=", np.mean(
    np.array([0.000107288, 0.000107193, 0.000104877, 0.000106845, 0.000106282])))

print("")

print("Gen, n=10e2, time=", np.mean(
    np.array([2.3978e-5, 2.4017e-5, 2.2044e-5, 2.4282e-5, 2.4132e-5])))
print("Opt, n=10e2, time=", np.mean(
    np.array([3.089e-6, 3.177e-6, 2.904e-6, 3.119e-6, 3.131e-6])))
print("LUd, n=10e2, time=", np.mean(
    np.array([0.00105449, 0.00107399, 0.00100461, 0.00107154, 0.00105949])))

print("")

print("Gen, n=10e3, time=", np.mean(
    np.array([6.665e-5, 6.7136e-5, 6.7594e-5, 6.936e-5, 6.8913e-5])))
print("Opt, n=10e3, time=", np.mean(
    np.array([2.6397e-5, 2.6868e-5, 2.6551e-5, 2.712e-5, 2.6752e-5])))
print("LUd, n=10e3, time=", np.mean(
    np.array([0.0990859, 0.095715, 0.0960053, 0.0988432, 0.105186])))

print("")

print("Gen, n=10e4, time=", np.mean(
    np.array([0.000519208, 0.000521486, 0.000526264, 0.000500258, 0.000505821])))
print("Opt, n=10e4, time=", np.mean(
    np.array([0.000280609, 0.000281583, 0.00028333, 0.000247253, 0.000280837])))
print("LUd, n=10e4, time=", np.mean(
    np.array([53.0148, 51.0797, 52.0334, 51.7968, 52.1834])))

print("")

print("Gen, n=10e5, time=", np.mean(
    np.array([0.00534878, 0.00499248, 0.00497204, 0.00514921, 0.00516681])))
print("Opt, n=10e5, time=", np.mean(
    np.array([0.0020745, 0.00207173, 0.00206066, 0.0020541, 0.00247636])))

print("")

print("Gen, n=10e6, time=", np.mean(
    np.array([0.0478849, 0.0470058, 0.047658, 0.0468383, 0.046578])))
print("Opt, n=10e6, time=", np.mean(
    np.array([0.026004, 0.0260386, 0.0262916, 0.0258869, 0.0258023])))
