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
double c = 63239.7263;       // Speed of light [AU/yr]

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
inline vec einstein(vec pos, vec vel)
//----------------------------------------------------------------------------
// Calculate relativistic gravity
//----------------------------------------------------------------------------
{
	double r = norm(pos);
	double l = abs(norm(cross(pos, vel)));
	return -G/pow(r, 3)*(1 + 3*l*l/(r*r*c*c))*pos;
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
	vec pos_mercury = vec({-1.323E-01, -4.393E-01, -2.444E-02}); // [AU]
	vec vel_mercury = vec({2.132E-02, 6.577E-03, -2.494E-03});   // [AU/day]
	vel_mercury *= 365.25;                                       // [AU/yr]
	double M_mercury = 0.166E-6;                                 // [solar mass]
	Planet Mercury(pos_mercury, vel_mercury, M_mercury);
	vector<Planet> solarsystem = vector<Planet>{Mercury};

	// Initialize solver
	Solver solver(solarsystem, G, true);

	// Solve motion
	solver.solve(2, einstein, T, N, sampleN);
	system("python3 precession.py");

	return 0;
}
//============================================================================
