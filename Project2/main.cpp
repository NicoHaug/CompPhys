#include <iostream>
#include <cmath>
#include <armadillo>
#include <fstream>
#include "eigvalSolver.h"

using namespace  std;
using namespace  arma;

// Functions used
vec analyticalEigval(double d, double a, int N);
mat makeMatrix(double d, double a, int N);
void bucklingBeam(double d, double a, int N);
void HO(double h, double d, double a, int N);

// Defining the global variables
double rho_0 = 0.0;
double rho_N = 5.0;
double omega = 1.0;

// Begin main program
int main(int argc, char *argv[])
{
		int N;                 // Number of mesh-points
		N = atoi(argv[1]);     // Read N as cmd-line arg

		double h = (rho_N-rho_0)/(N+1);
		//double h = 1/(N-1);
		double d = 2/(h*h);
		double a = -1/(h*h);

		mat A(N,N, fill::zeros);
		A.diag(-1).fill(a);
		A.diag(0).fill(d);
		A.diag(1).fill(a);

		bucklingBeam(d, a, N);
		HO(h, d, a, N);

		return 0;
}
// End main program


vec analyticalEigval(double d, double a, int N)
{
		vec ana_eigval(N);
		for (int j=1; j<N+1; j++) {
				ana_eigval[j-1] = d+2*a*cos((j*M_PI)/(N+1));
		}
		return ana_eigval;
}

mat makeMatrix(double d, double a, int N)
{
		mat A(N,N, fill::zeros);
		A.diag(-1).fill(a);
		A.diag(0).fill(d);
		A.diag(1).fill(a);

		return A;
}

//=============================================================================
vec armaSolve(d, a, N)
//----------------------------------------------------------------------------
// Solve eigenvalue problem with Armadillo's built-in function
//
// d - diagonal elements
// a - off-diagonal elements
// N - number of mesh points -> determines matrix dimensionality
//----------------------------------------------------------------------------
{
		mat A = makeMatrix(d, a, N);
		vec eigval;
		mat eigvec;
		eig_sym(eigval, eigvec, A);
		return eigval;
}
// End function

void bucklingBeam(double d, double a, int N)
{
		mat A = makeMatrix(d, a, N);
		vec eigval = jacobiMethod(A, N);
		vec ana_eigval = analyticalEigval(d, a, N);
		cout << "Numerical" << " " << "Analytical" << endl;
		cout << eigval(0) << " " << ana_eigval(0) << endl;
		cout << eigval(1) << " " << ana_eigval(1) << endl;
		cout << eigval(2) << " " << ana_eigval(2) << endl;

		/*
		   ofstream myfile;
		   myfile.open("BucklingBeam_results.txt");
		   for(int i = 0; i < N; i++) {
		        myfile << eigval[i] << " " << ana_eigval[i] << endl;
		   }
		   myfile.close();
		 */
}



void HO(double h, double d, double a, int N)
{
		vec rho = linspace(rho_0+h, rho_N-h, N);
		vec V = omega*omega*rho%rho;
		mat A = makeMatrix(d, a, N);
		A.diag(0) += V;
		vec eigval = jacobiMethod(A, N);
		/*
		   cout << eigval(0) << endl;
		   cout << eigval(1) << endl;
		   cout << eigval(2) << endl;
		 */
}
