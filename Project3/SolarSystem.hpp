#ifndef SOLAR_SYSTEM_HPP
#define SOLAR_SYSTEM_HPP

#include <armadillo>
#include <cmath>
#include <vector>
#include "ODEint.hpp"
using namespace std;
using namespace arma;

class Planet
{
public:
	vec position;
	vec velocity;
	double mass;
	Planet(){
		position = zeros(3);
		velocity = zeros(3);
		mass = 0;
	}

	Planet(vec position_, vec velocity_, double mass_){
		position = position_;
		velocity = velocity_;
		mass = mass_;
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
	// Quantities
	double G = 4*M_PI*M_PI;   // [AU^3/yr^2]
	double T;
	int N;
	int num_planets;          // Number of planets
	int sample_interval;
	vector<Planet> planets;

	mat position;
	mat velocity;
	mat acceleration;
	vec Force;

	// Methods
	vec newtonianGravity(vec position)
	{
		double rCube = pow(norm(position), 3);
		return -G/rCube*position;
	}

	vec einsteinGravity(vec position, vec velocity)
	{
		double rCube = pow(norm(position), 3);
		return -G/rCube*position;
	}

// Velocity independent force
	void totalAcceleration(mat &acceleration, mat &position)
	{
		acceleration = zeros(3, num_planets);
		for(int j=0; j<num_planets; j++)
		{
			acceleration.col(j) += newtonianGravity(position.col(j));
			for(int k=j+1; k<num_planets; k++)
			{
				vec rel_position = position.col(j) - position.col(k);
				mat temp = newtonianGravity(rel_position);
				acceleration.col(j) += planets[k].mass*temp;
				acceleration.col(k) -= planets[j].mass*temp;
			}
		}
	}

/*
   // Velocity dependent force
        void totalAcceleration(mat &acceleration, mat &position, mat &velocity)
        {
                acceleration = zeros(3, num_planets);
                for(int j=0; j<num_planets; j++)
                {
                        acceleration.col(j) += einsteinGravity(position.col(j), velocity.col(j));
                        for(int k=j+1; k<num_planets; k++)
                        {
                                vec rel_position = position.col(j) - position.col(k);
                                vec rel_velocity = velocity.col(j) - velocity.col(k);
                                mat temp = einsteinGravity(rel_position, rel_velocity);
                                acceleration.col(j) += planets[k].mass*temp;
                                acceleration.col(k) -= planets[j].mass*temp;
                        }
                }
        }
 */


public:
	// Constructor
	SolarSystem(vector<Planet> planets_){
		planets = planets_;
		num_planets = planets.size();
	}

// Destructor
	~SolarSystem(){
	};

// Methods

	void solveNewton(double T_, int N_, int sample_interval_){
		T = T_;
		N = N_;
		sample_interval = sample_interval_;
		position=zeros(3,num_planets);
		velocity=zeros(3,num_planets);
		acceleration=zeros(3,num_planets);



		// Initial conditions
		for(int i=0; i<num_planets; i++)
		{
			position.col(i) = planets[i].position;
			velocity.col(i) = planets[i].velocity;
		}
		totalAcceleration(acceleration, position);

		// Solve motion
		Verlet verlet;
		for (int i=0; i<N-1; i++) {
			verlet.integrate(position, velocity, totalAcceleration(acceleration, position),
			                 acceleration, T, N)
		}
	}

/*
        SolveEinstein(double T_, int N_, int sample_interval_, char[] method_){
                T = T_;
                N = N_;
                sample_interval = sample_interval_;
                method = method_;
                for (int i=0; i<N-1; i++) {
                        method::integrate
                }
        }
 */


};



#endif
