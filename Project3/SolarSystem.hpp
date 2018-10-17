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

//------------------------------------------------
class SolarSystem
//
// Constructor:
// SolarSystem SS(T, N, planet(s), method)
//
//------------------------------------------------
{
private:
	// Variables
	double GM = 4*M_PI*M_PI;   // [AU^3/yr^2]
	double T;
	int N;
	int num_planets;          // Number of planets
	int sample_interval;
	vector<Planet> planets;
	char[] method;
	mat acceleration;
	vec Force;


	vec newtonianGravity(vec position)
	{
		double rCube = pow(norm(pos), 3);
		return -G/rCube*pos;
	}

	vec einsteinGravity(vec position, vec velocity)
	{
		double rCube = pow(norm(pos), 3);
		return -G/rCube*pos;
	}

// Velocity independent force
	void totalAcceleration(mat &acceleration, mat &position)
	{
		acceleration = zeros(3, numPlanets);
		for(int j=0; j<num_planets; j++)
		{
			acceleration.col(j) += newtonianGravity(position.col(j));
			for(int k=j+1; k<num_planets; k++)
			{
				vec rel_position = position.col(j) - position.col(k);
				mat temp = newtonianGravity(rel_position);
				acceleration.col(j) += planets[k].M*temp;
				acceleration.col(k) -= planets[j].M*temp;
			}
		}
	}

// Velocity dependent force
	void totalAcceleration(mat &acceleration, mat &position, mat &velocity)
	{
		acceleration = zeros(3, numPlanets);
		for(int j=0; j<num_planets; j++)
		{
			acceleration.col(j) += einsteinGravity(position.col(j), velocity.col(j));
			for(int k=j+1; k<num_planets; k++)
			{
				vec rel_position = position.col(j) - position.col(k);
				vec rel_velocity = velocity.col(j) - velocity.col(k);
				mat temp = einsteinGravity(rel_position, rel_velocity);
				acceleration.col(j) += planets[k].M*temp;
				acceleration.col(k) -= planets[j].M*temp;
			}
		}
	}



public:
	// Constructor
	SolarSystem(double T_, int N_, vector<Planet> planets_, method_){
		T = T_;
		N = N_;
		planets = planets_;
		method = method_;
	}

// Destructor
	~SolarSystem(){
	};

// Methods

private:


public:

	Solve(){



		method::integrate
	}


	// Destructor


	// Methods



};



#endif
