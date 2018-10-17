#ifndef SOLAR_SYSTEM_HPP
#define SOLAR_SYSTEM_HPP

#include <armadillo>
#include <cmath>
#include <ODEint>
using namespace std;
using namespace arma;

class Planet
{
public:
	vec pos;
	vec vel;
	double M;
	Planet(){
		pos = zeros(3);
		vel = zeros(3);
		M = 0;
	}

	Planet(vec position, vec velocity, double mass){
		pos = position;
		vel = velocity;
		M = mass;
	}
};


class SolarSystem
{
private:
	double GM = 4*M_PI*M_PI;   // [AU^3/yr^2]
	double T;
	int N;
	int num_planets;          // Number of planets
	int sample_interval;
	vector<Planet> planets;



public:
	// Constructor


	// Destructor


	// Methods


	vec newton(vec pos, vec vel)
	{
		double rCube = pow(norm(pos), 3);
		return -scale/rCube*pos;
	}

};



#endif
