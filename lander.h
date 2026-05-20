#include <string>

#ifndef LANDER_H
#define LANDER_H

class lander
{
public:
	lander(std::string = "", double = 0, double = 0,
		double = 0, double = 0, double = 0);

	double get_velocity() const { return velocity; }
	double get_altitude() const { return altitude; }
	double get_fuel_amount() const { return fuel_amount; }
	std::string get_name() const { return name; }

	double get_mass() const { return lander_mass; }
	double get_max_thrust() const { return max_thrust; }

	char get_status() const;
	bool change_flow_rate(double);
	void simulate();

	bool operator<(const lander&) const;
private:
	std::string name;
	double flow_rate;
	double velocity;
	double altitude;
	double fuel_amount;
	bool stillLanding;
	double lander_mass;
	double max_fuel_consumption_rate;
	double max_thrust;
};

#endif



/*

notes from the video:

At the root surface we want that closest to the moon. 
we will constantly pop a space pod of the the priority queue and then update the thrust amount which will
update its distance and velocity. constantly pushing the spcae pod that is closest to the moon surface. 
and update it's thrust until it landed r crashes. 

Lander class:

we need to implement char get status() const, bool changeflow rate(double), and void simulate

keep in mind the less than operator to compare two objects which will be halpful for
priority = lander type template

she didnt say much but that this part is apart of the document pretty much.
*/