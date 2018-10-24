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
#include "./Classes/solver.h"
#include "./Classes/planet.h"
using namespace std;
using namespace arma;

//=================================
// Global variable(s)
double GM = 4*M_PI*M_PI;      // Gravitational constant*1 solar mass
double c = 63239.7263;        // Speed of light [AU/yr]

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
	return -GM/rCube*pos;
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
	return -GM/pow(r, 3)*(1 + 3*l*l/(r*r*c*c))*pos;
}
//============================================================================


//============================================================================
//-------------------------------- MAIN --------------------------------------
//============================================================================
int main(int argc, char *argv[])
//----------------------------------------------------------------------------
// Calculate the precession of the perihelion of Mercury
//----------------------------------------------------------------------------
{


	double T = 100;            // simulation time [years]
	int N = 1000000;          // N - number of integration points

	double M_sun = 1.0;              // [solar mass]

	// Initialize celestial bodies in the Solar System
	vec pos_mercury = vec({-1.323E-01, -4.393E-01, -2.444E-02}); // [AU]
	vec vel_mercury = vec({2.132E-02, 6.577E-03, -2.494E-03});   // [AU/day]
	vel_mercury *= 365.25;                                       // [AU/yr]
	double M_mercury = 0.166E-6;                                 // [solar mass]
	Planet Sun(vec({0,0,0}), vec({0,0,0}), M_sun);
	Planet Mercury(pos_mercury, vel_mercury, M_mercury);
	vector<Planet> solarsystem = vector<Planet>{Sun, Mercury};

	// Set motion properties of the Sun
	for (unsigned int i=1; i<solarsystem.size(); i++) {
		solarsystem[0].pos -= 1/solarsystem[0].M*solarsystem[i].M*solarsystem[i].pos;
		solarsystem[0].vel -= 1/solarsystem[0].M*solarsystem[i].M*solarsystem[i].vel;
	}

	// Initialize solver
	Solver solver(solarsystem, GM, false);

	// Solve motion
	solver.solvePerihelion(newton, T, N, "./Raw_Data/angle1.txt");
	solver.solvePerihelion(einstein, T, N, "./Raw_Data/angle2.txt");

	system("python3 plot.py precession");

	return 0;
}
//============================================================================
