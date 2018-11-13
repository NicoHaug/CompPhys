//=================================
// Include guard
#ifndef METROPOLIS_HPP
#define METROPOLIS_HPP

//=================================
// Included dependencies
#include <iostream>
#include <armadillo>
#include <cmath>
#include <random>
#include <map>

using namespace std;
using namespace arma;


//=============================================================================
//-------------------------------- CLASS --------------------------------------
//=============================================================================
class Metropolis
//----------------------------------------------------------------------------
// Solve the Ising model with the Metropolis algorithm
//----------------------------------------------------------------------------
{
private:
	//==========================
	// Declare private variables
	//==========================
	Mat<int> spinMatrix;   // Matrix with spin configurations
	map<double, double> denergy;

	//=====================
	// Private methods
	//=====================

	// Periodic Boundary Conditions
	int PBC(int index, int correction, int limit);

	// Initialize lattice and characteristics
	void initialize();


public:
	//==========================
	// Declare public variables
	//==========================
	int L;                 // Lattice Dimenstionality LxL
	double J;              // Coupling constant
	double T;              // Temperature
	double energy;         // Energy of the system
	double magneticMoment;  // Magnetization of the system
	double deltaE;         // Energy change when spin flip
	double deltaM;         //change in magnetization when flipping single spin
	int accepted;          // number of accepted flips
	bool randomConfig;     // Random spin configuration is true, ordered=false
	vec ExpectationValues;
	int MCcycles;


	//================
	// CONSTRUCTOR(S)
	//================
	Metropolis();

	Metropolis(int L, double T, double J);

	Metropolis(int L, double T, double J, bool randomConfig);


	//================
	// DESTRUCTOR
	//================
	~Metropolis();


	//=====================
	// Public methods
	//=====================

	// Metropolis algorithm
	void solve(int MCcycles);

	// Solve with MPI
	void solve_MPI(int MCcycles);

	// Output results
	void output();


};
//=============================================================================

#endif // __METROPOLIS_HPP_INCLUDED__
