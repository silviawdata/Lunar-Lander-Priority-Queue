/*
 * Name: Silvia Williams
 * Description: This program implements  the lander class.
 * It updates lander status, flow rate, velocity, altitude
 * fuel amount, and compares landers by priory.
 * Input: Lander data from main.cpp
 * Output: Lander values returned to main.cpp
 *
 */
#include "lander.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

const int TIME = 1; // 1 second of time for the simulation function
///////// LANDER - CONSTRUCTOR FUNCTION /////////
lander::lander(string name, double mass, double thrust, double max_fuel,
			   double alt, double fuel)
{
	lander_mass = mass;
	max_thrust = thrust;
	max_fuel_consumption_rate = max_fuel;

	stillLanding = true;
	flow_rate = 0.0;
	velocity = 0.0;
	altitude = alt;
	fuel_amount = fuel;
	this->name = name;
}

///////// LANDER  - GET STATUS FUNCTION /////////
char lander::get_status() const
{

	if (stillLanding)
	{

		return 'a'; // a = if still airborne
	}

	if (velocity <= -2)
	{

		return 'c'; // c = if crashed
	}

	return 'l'; // l = if landed safely
}

///////// LANDER - CHANGE FLOW RATE FUNCTION /////////
/*
sets throttle/ flow rate for the lander
r must be between 0 and 1
if there is no fuel, flow rate is set to 0
returns true if sucessful, false if invalid input
*/
bool lander::change_flow_rate(double r)
{
	if (r < 0 || r > 1 )
	{

		return false;
	}
	if (fuel_amount == 0)
	{

		flow_rate = 0;
		return true;
	}

	flow_rate = r;
	return true;
}

///////// LANDER - SIMULATE FUNCTION ////////
/*
Calculates acceleration using:
TIME, flow rate, max thrust, lander mass, fuel amount, and moon gravity
checks if lander has reached the surface
updates fuel ussage based on flow rate
ensures fuel does not go below 0
*/
void lander::simulate()
{
	if (stillLanding)
	{
		double v = TIME * ((flow_rate * max_thrust) /
							   (lander_mass + fuel_amount) - 1.62);

		velocity = velocity + v;

		altitude = altitude + (TIME * velocity );

		if (altitude <= 0)
		{

			altitude = 0;
			stillLanding = false;
		}
		if (flow_rate > 0)
		{

			fuel_amount = fuel_amount -
						  ( TIME * max_fuel_consumption_rate * abs(v));
		}

		if (fuel_amount < 0)
		{

			fuel_amount = 0;
		}
	}
}
///////// LANDER - LESS THAN OPERATOR FUNCTION /////////
/*
compares two landers by priority
smaller altitude has higher priority
then less fuel, larger mass, and earlier name
*/
bool lander::operator<(const lander &rhs) const
{

	if (altitude != rhs.altitude)
	{

		return altitude < rhs.altitude;
	}

	if (fuel_amount != rhs.fuel_amount)
	{

		return fuel_amount < rhs.fuel_amount;
	}

	if (lander_mass != rhs.lander_mass)
	{

		return lander_mass > rhs.lander_mass;
	}

	return name < rhs.name;
}
