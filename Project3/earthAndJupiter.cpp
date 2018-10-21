//=================================
// Included dependencies
#include <iostream>
#include <iomanip>
#include <armadillo>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include "Classes/solver.h"
#include "Classes/planet.h"
using namespace std;
using namespace arma;

//=================================
// Global variable(s)
double G = 4*M_PI*M_PI;      // Gravitational constant


//===================================
//------------ FUNCTIONS ------------
//===================================

//============================================================================
inline vec newton(vec pos, vec vel)
//----------------------------------------------------------------------------
// Calculate newtonian gravity
//----------------------------------------------------------------------------
{
	double rCube = pow(norm(pos), 3);
	return -G/rCube*pos;
}
//============================================================================


//============================================================================
//-------------------------------- MAIN --------------------------------------
//============================================================================
int main(int argc, char *argv[])
//----------------------------------------------------------------------------
// Simulate motion of the Solar System
//
// Command line arguments:
// T - simulation time [years]
// N - number of integration points
// n - sample point interval
//----------------------------------------------------------------------------
{
	// Check if the user is supplying enough commandline arguments
	if (argc < 4)
	{
		cout << "Bad usage! \n";
		cout << "Please supply:\n";
		cout << "Simulation time T\n";
		cout << "Number of time points N\n";
		cout << "Sample point interval sampleN"<< endl;
		return 1;
	}

	double T = atof(argv[1]);
	int N = atoi(argv[2]);
	int sampleN = atoi(argv[3]);

	// Initialize celestial bodies in the Solar System
	Planet Earth(vec({1,0,0}), vec({0,2*M_PI,0}),3e-6);
	Planet Jupiter(vec({5,0,0}), vec({0,3,0}),1);
	vector<Planet> solarsystem = vector<Planet>{Earth, Jupiter};

	// Initialize solver
	Solver solver(solarsystem, G, true);

	// Solve motion
	solver.solve(2, newton, T, N, sampleN);
	system("python3 plot.py pos");

	return 0;
}
//============================================================================
