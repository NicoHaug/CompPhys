//=================================
// Included dependencies
#include <iostream>
#include <armadillo>
#include <cmath>
#include <random>
#include "metropolis.hpp"
#include <map>

using namespace std;
using namespace arma;

//================
// CONSTRUCTOR(S)
//================
Metropolis::Metropolis()
{
	L = 2;
	T = 1;
	J = 1;
	randomConfig = true;
	ExpectationValues = zeros<mat>(5);
}

Metropolis::Metropolis(int L, double T, double J)
{
	this->L = L;
	this->T = T;
	this->J = J;
	randomConfig = true;
	ExpectationValues = zeros<mat>(5);
}

Metropolis::Metropolis(int L, double T, double J, bool randomConfig)
{
	this->L = L;
	this->T = T;
	this->J = J;
	this->randomConfig = randomConfig;
	ExpectationValues = zeros<mat>(5);
}

//================
// DESTRUCTOR
//================
Metropolis::~Metropolis(){
};


//========================================================
int Metropolis::PBC(int index, int correction, int limit)
//--------------------------------------------------------
// Periodic Boundary Conditions
//--------------------------------------------------------
{
	return (index+correction+limit)%(limit);
}
//========================================================

//========================================================
void Metropolis::initialize()
//--------------------------------------------------------
// Initialize lattice and characteristics
//--------------------------------------------------------
{
	random_device rd;
	mt19937_64 generator(rd());
	uniform_int_distribution<int> rng_int(0, 1);
	// Initialize the lattice spin values

	if (randomConfig) {
		spinMatrix = zeros<Mat<int> >(L,L);
		for (int i=0; i<L; i++) {
			for (int j=0; j<L; j++) {
				spinMatrix(i,j) = 2*rng_int(generator) - 1;
			}
		}
	}
	else {
		spinMatrix = ones<Mat<int> >(L,L);
	}

	// Setup initial energy and initial magnetization
	for (int i=0; i<L; i++) {
		for (int j=0; j<L; j++) {
			energy -= spinMatrix(i,j)*(spinMatrix(PBC(i, -1, L), j) +
			                           spinMatrix(i, PBC(j, -1, L)));
			magneticMoment += spinMatrix(i, j);
		}
	}

	// setup array for possible changes in energy
	for (int de=-8; de<=8; de+=4) {
		denergy.insert(pair<double, double>(de, exp(-de/T)));
	}
}
//========================================================

//========================================================
void Metropolis::solve(int MCcycles)
//--------------------------------------------------------
// Metropolis algorithm
//--------------------------------------------------------
{
	this->MCcycles = MCcycles;
	initialize();
	random_device rd;
	mt19937_64 generator(rd());
	uniform_real_distribution<float> rng_real(0.0, 1.0);
	uniform_int_distribution<int> rng_coord(0, L-1);
	// Begin MC cycles
	for (int cycles=1; cycles <= MCcycles; cycles++) {
		// Sweep over lattice
		for (int x = 0; x < L; x++) {
			for (int y = 0; y < L; y++) {
				int ix = int(rng_coord(generator));
				int iy = int(rng_coord(generator));
				int deltaE =  2*spinMatrix(ix,iy)*
				             (spinMatrix(ix, PBC(iy, -1, L))+
				              spinMatrix(PBC(ix,-1, L), iy) +
				              spinMatrix(ix, PBC(iy, 1, L)) +
				              spinMatrix(PBC(ix, 1, L), iy));


				if (rng_real(generator) <= denergy.find(deltaE)->second) {
					spinMatrix(ix,iy) *= -1.0;         // flip one spin and accept new spin config
					magneticMoment += (double) 2*spinMatrix(ix,iy);
					energy += (double) deltaE;
					accepted++;
				}
			}
		}
		// update expectation values  for local node
		ExpectationValues(0) += energy;
		ExpectationValues(1) += energy*energy;
		ExpectationValues(2) += magneticMoment;
		ExpectationValues(3) += magneticMoment*magneticMoment;
		ExpectationValues(4) += fabs(magneticMoment);
	}        //end MC loop

	output();
}
//========================================================


//========================================================
void Metropolis::solve_MPI(int MCcycles)
//--------------------------------------------------------
// Solve with MPI
//--------------------------------------------------------
{
	this->MCcycles = MCcycles;

}
//========================================================


//========================================================
void Metropolis::output()
//--------------------------------------------------------
// Output results
//--------------------------------------------------------
{
	double norm = 1.0/((double) (MCcycles));
	// divided by  number of cycles
	// all expectation values are per spin, divide by 1/(L*L)
	double E_mean = ExpectationValues(0)*norm/(L*L);
	double E2_mean = ExpectationValues(1)*norm/(L*L);
	//double M_mean = ExpectationValues(2)*norm/(L*L);
	double M2_mean = ExpectationValues(3)*norm/(L*L);
	double Mabs_mean = ExpectationValues(4)*norm/(L*L);

	double E_var = (E2_mean - E_mean*E_mean);
	double M_var = (M2_mean - Mabs_mean*Mabs_mean);
	double Cv = 1/(T*T)*E_var;
	double chi = 1/T*M_var;

	cout << "Mean energy: " << E_mean << "\n";
	cout << "Mean absolute magnetic moment: " << Mabs_mean << "\n";
	cout << "Heat capacity: " << Cv << "\n";
	cout << "Susceptibility: " << chi << endl;
	/*
	   ofile << setiosflags(ios::showpoint | ios::uppercase);
	   ofile << setw(15) << setprecision(8) << temperature;
	   ofile << setw(15) << setprecision(8) << E_ExpectationValues/NSpins/NSpins;
	   ofile << setw(15) << setprecision(8) << E2_ExpectationValues/NSpins/NSpins;//Evariance/temperature/temperature;
	   ofile << setw(15) << setprecision(8) << M_ExpectationValues/NSpins/NSpins;//M_ExpectationValues/NSpins/NSpins;
	   ofile << setw(15) << setprecision(8) << M2_ExpectationValues/NSpins/NSpins; //Mvariance/temperature;
	   ofile << setw(15) << setprecision(8) << Mabs_ExpectationValues/NSpins/NSpins << endl;
	 */
}
//========================================================
