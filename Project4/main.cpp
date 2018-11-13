//=================================
// Included dependencies

 #include <iostream>
 #include <armadillo>
 #include <cmath>
 #include <random>
 #include "./Classes/metropolis.hpp"
 #include <map>

using namespace std;
using namespace arma;

//============================================================================
//-------------------------------- MAIN --------------------------------------
//============================================================================
int main(int argc, char const *argv[])
//----------------------------------------------------------------------------
// Short description
//----------------------------------------------------------------------------
{

	int L = 2;   // Lattice
	double T= 1; // Temperature
	int J = 1;   // Coupling
	int MCcycles = 100000;  // number of MC cycles

	Metropolis ising(L, T, J);
	ising.solve(MCcycles);
	cout << "Accepted configurations: " << ising.accepted << " of " << MCcycles << endl;


	return 0;
}
//============================================================================
