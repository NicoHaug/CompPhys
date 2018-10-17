#include <iostream>
#include <iomanip>
#include <armadillo>
#include <fstream>
#include <vector>
#include "SolarSystem.hpp"
#include "ODEint.hpp"

using namespace std;
using namespace arma;


int main(int argc, char const *argv[])
{
	double T;           // Simulation Time
	int N;              // Number of time steps
	T = atof(argv[1]);
	N = atoi(argv[2]);

	Planet Earth({1,0,0}, {0, 2*M_PI, 0}, 1);
	vector<Planet> planets = vector<Planet>{Earth};

	SolarSystem solarsystem(planets);
	solarsystem.solveNewton(T, N, 1);

	return 0;
}
