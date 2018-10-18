#ifndef ODEINT_H
#define ODEINT_H

#include <armadillo>
using namespace std;
using namespace arma;

class Acceleration {
public:
	Acceleration();
	void totalAcceleration(mat &acceleration, mat &position, mat &velocity);
};


class Solver
{
protected:
	double dt;
public:
	Solver();
	virtual void integrate(mat &position, mat &velocity, mat &acceleration, double T, int N);
	virtual void integrate(mat &position, mat &velocity, Acceleration acc,
	                       mat &acceleration, double T, int N);

};


class Euler : public Solver
{

public:
	// Constructor
	Euler();
	// Destructor
	/*
	      ~Euler(){
	      };
	 */

	void integrate(mat &position, mat &velocity, mat &acceleration, double T, int N)
	{
		dt = T/N;
		velocity += velocity + acceleration*dt;
		position += position + velocity*dt;
	}
};


class Verlet : public Solver
{
private:
	mat prev_acc;
public:
	// Constructor
	Verlet();
	// Destructor
	/*
	      ~Verlet(){
	      };
	 */

	//template <typename F>

	void integrate(mat &position, mat &velocity, Acceleration acc,
	               mat &acceleration, double T, int N)
	{
		dt = T/N;

		position += position + velocity + 0.5*acceleration*dt*dt;
		prev_acc = acceleration;
		acc.totalAcceleration(acceleration, position, velocity);
		velocity += velocity + 0.5*dt*(acceleration + prev_acc);

	}


	// Velocity dependent
	/*
	      void integrateVelocityDep(mat &position, mat &velocity,
	                                void calcacc(mat &acceleration, mat &position,
	                                              mat &velocity), mat &acceleration,
	                                double T, int N)
	      {
	              dt = T/N;

	              position += position + velocity + 0.5*acceleration*dt*dt;
	              prev_acc = acceleration;
	              calcacc(acceleration, position, velocity);
	              velocity += velocity + 0.5*dt*(acceleration + prev_acc);
	              calcacc(acceleration, position, velocity);
	      }
	 */

};  //end class
#endif
