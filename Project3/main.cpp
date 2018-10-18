#include <iostream>
#include <iomanip>
#include <armadillo>
#include <fstream>
#include <vector>
#include "SolarSystem.hpp"
#include "ODEint.hpp"

using namespace std;
using namespace arma;

double G = 4*M_PI*M_PI;

vec newtonianGravity(vec position, vec velocity)
{
	double rCube = pow(norm(position), 3);
	return -G/rCube*position;
}

vec einsteinGravity(vec position, vec velocity)
{
	double rCube = pow(norm(position), 3);
	return -G/rCube*position;
}

int main(int argc, char const *argv[])
{
	double T;           // Simulation Time
	int N;              // Number of time steps
	T = atof(argv[1]);
	N = atoi(argv[2]);

	Planet Earth({1,0,0}, {0, 2*M_PI, 0}, 1);
	vector<Planet> planets = vector<Planet>{Earth};

	Verlet verlet;
	TotalAcc totalacc(newtonianGravity, planets);

	SolarSystem solarsystem(planets);
	solarsystem.solve(T, N, verlet, totalacc);


	return 0;
}
