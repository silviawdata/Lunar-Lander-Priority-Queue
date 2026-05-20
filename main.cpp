/*
 * Name: Silvia Williams
 * Description: This program reads lander data from a file,
 * stores the landers in a priority queue, updates each lander
 * based on user name and throttle input, and outputs the top 3 landers.
 * Input: LanderInput.txt and user input for lander name and throttle.
 * Output: Top 3 landers, updated lander info, prompts and status.
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "priorityQ.h"
#include "lander.h"
using namespace std;
/////////  INT MAIN /////////////////////////////
/*
reads in lander data from file, stores in the priority queue, 
simulates the lander movements based on user input, 
and outputs leaderboard after each update.
*/
int main()
{
	priorityQ<string, lander> raceToTheMoon;
	ifstream infile("LanderInput.txt");
	double mass, max_thrust, max_fuel, alt, fuel;
	string name;

	////// string prompts for output //////
	string prompt1 = "Enter lander name and throttle amount: ";
	string promptM = " meters from the moon surface";
	string promptT = "traveling at ", promptS = " m/s";
	string promptF = "Fuel: ", crash = " crashed :(", land = " landed :) ";

	/// reading lander data from file 
	while (infile >> name >> mass >> max_thrust >> max_fuel >> alt >> fuel)
	{
		// create lander object and inserts into priority queue
		lander tempSpaceShip(name, mass, max_thrust, max_fuel, alt, fuel);
		raceToTheMoon.push_back(name, tempSpaceShip);
	}

	//close file
	infile.close();

	//getting the top 3 landers//

	//gets the name/key of the top lander
	// store it into spaceKey1
	string spaceKey1 = raceToTheMoon.get_front_key();

	//gets the lander object of (altitude, velocity, fuel) of the top lander
	// store it into spaceLander1
	lander spaceLander1 = raceToTheMoon.get_front_priority();

	//removes that lander from the priority queue
	raceToTheMoon.pop_front();

	string spaceKey2 = raceToTheMoon.get_front_key();
	lander spaceLander2 = raceToTheMoon.get_front_priority();
	raceToTheMoon.pop_front();

	string spaceKey3 = raceToTheMoon.get_front_key();
	lander spaceLander3 = raceToTheMoon.get_front_priority();
	raceToTheMoon.pop_front();

	/////////// outputs the top 3 landers on the terminal //////////////
	cout << fixed << setprecision(6) << endl;

	cout << "(1) Name: " << spaceKey1 << " "
		 << spaceLander1.get_altitude() << promptM << "\n"
		 << promptT << spaceLander1.get_velocity() << promptS << "\n"
		 << promptF << spaceLander1.get_fuel_amount() << endl
		 << endl;

	cout << "(2) Name: " << spaceKey2 << " "
		 << spaceLander2.get_altitude() << promptM << "\n"
		 << promptT << spaceLander2.get_velocity() << promptS << "\n"
		 << promptF << spaceLander2.get_fuel_amount() << endl
		 << endl;

	cout << "(3) Name: " << spaceKey3 << " "
		 << spaceLander3.get_altitude() << promptM << "\n"
		 << promptT << spaceLander3.get_velocity() << promptS << "\n"
		 << promptF << spaceLander3.get_fuel_amount() << endl
		 << endl;

	// push the top three back into the priority queue //////////////
	raceToTheMoon.push_back(spaceKey1, spaceLander1);
	raceToTheMoon.push_back(spaceKey2, spaceLander2);
	raceToTheMoon.push_back(spaceKey3, spaceLander3);

	///// While loop for processing user input and simulating lander movements

	double throttle; // throttle amount entered by user
	cout << prompt1 << endl;

	while (cin >> name >> throttle)
	{
		// Process the input
		// get lander
		lander currentLander = raceToTheMoon.get_element(name);

		// update throttle
		currentLander.change_flow_rate(throttle);

		// simulate lander
		currentLander.simulate();

		// update back into PQ
		raceToTheMoon.update_element(name, currentLander);

		// checks if lander crashes or lands, print message and pop from PQ
		//if no landers left, exit loop
		if (currentLander.get_status() == 'c')
		{

			cout << name << crash << endl;
			raceToTheMoon.pop_front();
		}
		else if (currentLander.get_status() == 'l')
		{

			cout << name << land << endl;
			raceToTheMoon.pop_front();
		}

		if (raceToTheMoon.isEmpty())
		{

			break;
		}

		int count = 0; //count to keep track of how many landers 
					//are retrieved from the queue for printing

		// get the top 3 landers from the queue, if they exist,
		// store their name and lander object and pop them from the queue
		// and count keeps track of how many were retrieved
		if (!raceToTheMoon.isEmpty())
		{

			spaceKey1 = raceToTheMoon.get_front_key();
			spaceLander1 = raceToTheMoon.get_front_priority();
			raceToTheMoon.pop_front();
			count++;
		}

		if (!raceToTheMoon.isEmpty())
		{

			spaceKey2 = raceToTheMoon.get_front_key();
			spaceLander2 = raceToTheMoon.get_front_priority();
			raceToTheMoon.pop_front();
			count++;
		}

		if (!raceToTheMoon.isEmpty())
		{

			spaceKey3 = raceToTheMoon.get_front_key();
			spaceLander3 = raceToTheMoon.get_front_priority();
			raceToTheMoon.pop_front();
			count++;
		}

		// prints leaderboard of the top 3 landers,
		// based on how many landers are available in the queue
		
		if (count >= 1) // if there is at least one lander, print the top lander
		{
			cout << "(1) Name: " << spaceKey1 << " "
				 << spaceLander1.get_altitude() << promptM << "\n"
				 << promptT << spaceLander1.get_velocity() << promptS << "\n"
				 << promptF << spaceLander1.get_fuel_amount() << endl
				 << endl;
		}
		if (count >= 2) // if there are at least two landers, print the second lander
		{
			cout << "(2) Name: " << spaceKey2 << " "
				 << spaceLander2.get_altitude() << promptM << "\n"
				 << promptT << spaceLander2.get_velocity() << promptS << "\n"
				 << promptF << spaceLander2.get_fuel_amount() << endl
				 << endl;
		}
		if (count >= 3) // if there are at least three landers, print the third lander
		{
			cout << "(3) Name: " << spaceKey3 << " "
				 << spaceLander3.get_altitude() << promptM << "\n"
				 << promptT << spaceLander3.get_velocity() << promptS << "\n"
				 << promptF << spaceLander3.get_fuel_amount() << endl
				 << endl;
		}

		// push the landers back into the priority queue
		// this logic matches the printing logic.
		// so that we only push back the landers that were retrieved from the queue
		if (count >= 1) // if there is at least one lander, push the top lander back into the queue
		{
			raceToTheMoon.push_back(spaceKey1, spaceLander1);
		}

		if (count >= 2) // if there are at least two landers, push the second lander back into the queue
		{
			raceToTheMoon.push_back(spaceKey2, spaceLander2);
		}

		if (count >= 3) // if there are at least three landers, push the third lander back into the queue
		{
			raceToTheMoon.push_back(spaceKey3, spaceLander3);
		}

		cout << prompt1 << endl;
	}

	return 0;
}
