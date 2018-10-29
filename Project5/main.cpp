//=================================
// Included dependencies
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//=================================
// Global variable(s)

//===================================
//------------ FUNCTIONS ------------
//===================================

//============================================================================
inline double template (double T, int N)
//----------------------------------------------------------------------------
// Short description
//----------------------------------------------------------------------------
{
	return 0;
}
//============================================================================



//============================================================================
//-------------------------------- MAIN --------------------------------------
//============================================================================
int main(int argc, char const *argv[])
//----------------------------------------------------------------------------
// Short description
//
// Command line arguments:
// T - simulation time
// N - number of integration points
//----------------------------------------------------------------------------
{
	// Check if the user is supplying enough commandline arguments
	if (argc < 3)
	{
		cout << "Bad usage! \n";
		cout << "Please supply:\n";
		cout << "Simulation time T\n";
		cout << "Number of integration points N" << endl;
		return 1;
	}

	double T = atof(argv[1]);
	int N = atoi(argv[2]);



	return 0;
}
//============================================================================
