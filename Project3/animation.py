#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import mpl_toolkits.mplot3d.axes3d as p3


def extract_data(filename):
    X = np.loadtxt(filename, usecols=0)
    Y = np.loadtxt(filename, usecols=1)
    Z = np.loadtxt(filename, usecols=2)
    return X, Y, Z


def planets_data(filename, N):
    for i in range(N):

    positions = np.loadtxt(filename)
    num_planets = int(X.size / N)
    planets = {1: 'Mercury', 2: 'Venus', 3: 'Earth', 4: 'Mars', 5: 'Jupiter',
               6: 'Saturn', 7: 'Uranus', 8: 'Neptune', 9: 'Pluto'}


def next_frame(filename):
    X, Y, Z = extract_data(filename)


def create_animation(filename, T, N):
    dt = T / N

    ani = animation.FuncAnimation(fig,
                                  next_frame(),
                                  frames=range(N),
                                  repeat=None,
                                  interval=1000 * dt,
                                  blit=True)
    return 0


def next_frame(filename, T, N):

    for mercury, venus in data:
        mercury.set_3d_properties()

    self.pendulums.set_data((0, self.x1[i], self.x2[i]),
                            (0, self.y1[i], self.y2[i]))
    self.trace_pendulum1.set_data(self.x1[:i], self.y1[:i])
    self.trace_pendulum2.set_data(self.x2[:i], self.y2[:i])

    for line, data in zip(lines, dataLines):
        # NOTE: there is no .set_data() for 3 dim data...
        line.set_data(data[0:2, :num])
        line.set_3d_properties(data[2, :num])
    return lines

####


def Gen_RandLine(length, dims=2):
    """
    Create a line using a random walk algorithm

    length is the number of points for the line.
    dims is the number of dimensions the line has.
    """
    lineData = np.empty((dims, length))
    lineData[:, 0] = np.random.rand(dims)
    for index in range(1, length):
        # scaling the random numbers by 0.1 so
        # movement is small compared to position.
        # subtraction by 0.5 is to change the range to [-0.5, 0.5]
        # to allow a line to move backwards.
        step = ((np.random.rand(dims) - 0.5) * 0.1)
        lineData[:, index] = lineData[:, index - 1] + step

    return lineData


def update_lines(num, dataLines, lines):
    for line, data in zip(lines, dataLines):
        # NOTE: there is no .set_data() for 3 dim data...
        line.set_data(data[0:2, :num])
        line.set_3d_properties(data[2, :num])
    return lines


# Attaching 3D axis to the figure
fig = plt.figure()
ax = p3.Axes3D(fig)

# Fifty lines of random 3-D lines
data = [Gen_RandLine(25, 3) for index in range(50)]

# Creating fifty line objects.
# NOTE: Can't pass empty arrays into 3d version of plot()
lines = [ax.plot(dat[0, 0:1], dat[1, 0:1], dat[2, 0:1])[0] for dat in data]

# Setting the axes properties
ax.set_xlim3d([0.0, 1.0])
ax.set_xlabel('X')

ax.set_ylim3d([0.0, 1.0])
ax.set_ylabel('Y')

ax.set_zlim3d([0.0, 1.0])
ax.set_zlabel('Z')

ax.set_title('3D Test')

# Creating the Animation object
line_ani = animation.FuncAnimation(fig, update_lines, 25, fargs=(data, lines),
                                   interval=50, blit=False)

plt.show()

#########


def create_animation(self):
    fig = plt.figure()
    r = 0.05
    plt.gca().set_xlim(-self.L1 - self.L2 - r, self.L1 + self.L2 + r)
    plt.gca().set_ylim(-self.L1 - self.L2 - r, self.L1 + self.L2 + r)
    plt.gca().set_aspect('equal')
    plt.axis('off')

    self.pendulums, = plt.plot([], [], 'k-', lw=2)
    self.trace_pendulum1, = plt.plot([], [], 'b:', lw=1)
    self.trace_pendulum2, = plt.plot([], [], 'r:', lw=1)
    self.c0, = plt.plot([], [], 'ko', markersize=5)
    self.c1, = plt.plot([], [], 'bo', markersize=8)
    self.c2, = plt.plot([], [], 'ro', markersize=8)
    self.time_text = plt.gca().text(0.05, 0.9, '',
                                    transform=plt.gca().transAxes)

    self.animation = animation.FuncAnimation(fig,
                                             self._next_frame,
                                             frames=range(self.t.size),
                                             repeat=None,
                                             interval=1000 * self._dt,
                                             blit=True)


def _next_frame(self, i):
    self.pendulums.set_data((0, self.x1[i], self.x2[i]),
                            (0, self.y1[i], self.y2[i]))
    self.trace_pendulum1.set_data(self.x1[:i], self.y1[:i])
    self.trace_pendulum2.set_data(self.x2[:i], self.y2[:i])
    self.c0.set_data(0, 0)
    self.c1.set_data(self.x1[i], self.y1[i])
    self.c2.set_data(self.x2[i], self.y2[i])
    self.time_text.set_text('time = {0:0.1f}s'.format(i * self._dt))

    return self.pendulums, self.trace_pendulum1, self.trace_pendulum2,\
        self.c0, self.c1, self.c2, self.time_text


def show_animation(self):
    self.create_animation()
    self.animation
    plt.show()


def save_animation(self, filename, fps=60):
    self.create_animation()
    self.animation.save(filename, fps=60)
