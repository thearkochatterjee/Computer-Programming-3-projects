// Datatype
// Programmer: Arko Chatterjee
//
// Purpose: Example of varible declaration and initialization

#include "stdafx.h"
#include <iostream>
using namespace std; // necessary for using cin and cout

//varible declaration
char ans; // store answer for do while loop

int _tmain(int argc, _TCHAR* argv[])
{
	do // loops the code to run more than once
	{
	// declare a constant for the square root of two
	const double SQUARE_ROOT_OF_TWO = 1.414214;

	// varible declaration
	int i; // this stores integers
	long j; // this stores integers that can range higher than that of int
	unsigned long k; // this stores only positive values in long
	float n; // this stores decimal places in addition to positive and negative number values
	float wait; // this is to wait till the user sees the results and then can close
	int s; // stores speed
	int ss1; // stores the speed of sound
	int sl; // stores the spped of light
	int ss2; // stores the speed of sound
	

	// inputs values into the varibles
	i = 3;
	j = -2048111;
	k = 4000000001;
	n = 1.887;
	s = 100;
	sl = -1000;
	ss1 = -40000;
	ss2 = 40000;

	// output constant and varibles to screen
	cout << SQUARE_ROOT_OF_TWO << '\n';
	cout << i << '\n';
	cout << j << '\n';
	cout << k << '\n';
	cout << n << '\n';
	cout << s << " e(2.7182818)" << '\n';
	cout << sl << " Speed of light(3.00 * 10^8 m/s)" << '\n';
	cout << ss1 << " Speed of sound (340.292 m/s)" << '\n';
	cout << ss2 << '\n';

	// ask user if they want to run again
	cout << "Do you want to run again (Y/N)?\n";
	cout << "You must type a 'Y' or an 'N'.\n";
	cin >> ans;

	} while ((ans == 'Y') | (ans == 'y'));
	return 0;
}

