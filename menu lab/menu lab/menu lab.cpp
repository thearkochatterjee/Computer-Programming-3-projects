// chapter 5 lab
// Programmer: Arko Chatterjee
//
// Purpose: using a menu to run different applications

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	system("color 30");
	// varible declaration
	int mnuc; // menu choice
	int apt; // amount of people to transport
	int bus; // amount of buses needed
	int van; // amount of people will need to travel by van
	float axis1; // length of axis 1
	float axis2; // length of axis 2
	float area; // area of the ellipse
	float rad; // radians
	float deg; // degrees
	float mph; // miles per hour
	float fps; // feet per second
	float si; // simple interest
	float p; // principle
	float ir; // interest rate
	float t; // time(years)
	float v; // voltage
	float r; // resistance
	float i; // current in amps
	float f; // force in newtons
	float m; // mass in kilograms
	float a; // acceleration in meters/second
	float e; // energy
	float s; // speed
	float fee; //fee
	float c; // celsius
	float temp; // tempurature
	float len; // length
	float nlen; // new length
	char ans; // asks user if they would like to run program again

	do
	{
		// ask user for input
		cout << "Press 1 for Transportation\n";
		cout << "Press 2 for Mathematics\n";
		cout << "Press 3 for Mathematics\n";
		cout << "Press 4 for Speed\n";
		cout << "Press 5 for Finance\n";
		cout << "Press 6 for Electricity\n";
		cout << "Press 7 for Physics\n";
		cout << "Press 8 for Physics\n";
		cout << "Press 9 for Law Enforcement\n";
		cout << "Press 10 for Surveying\n";
		cin >> mnuc;
		cout << endl;

		// tests choice
		if (mnuc == 1)
		{
			cout << "How many people do you want to transport?\n";
			cin >> apt;
			cout << endl;
			bus = apt / 50;
			cout << "Need to charter " << bus << " bus(es)\n";
			if (apt % 50 == 0)
			{
				cout << "You will not need any vans\n";
			}
			else
			{
				van = apt % 50;
				cout << van << " will need to travel by van\n";
			}
		}
		else if (mnuc == 2)
		{
			cout << "What is the measuremet of axis 1?\n";
			cin >> axis1;
			cout << "what is the measurement of axis 2?\n";
			cin >> axis2;
			cout << endl;
			area = axis1 * axis2 * 3.14159;
			cout << "The area of the ellipse is " << area << endl;
		}
		else if (mnuc == 3)
		{
			cout << "What is the amount of degrees you want to convert to radians\n";
			cin >> deg;
			cout << endl;
			rad = deg / 57.3;
			cout << deg << " degrees is " << rad << " radians\n";
		}
		else if (mnuc == 4)
		{
			cout << "What is the miles per hour?\n";
			cin >> mph;
			cout << endl;
			fps = mph * 1.4666666666667;
			cout << mph << " miles per hour is equal to " << fps << " feet per second\n";
		}
		else if (mnuc == 5)
		{
			cout << "What is the principle?\n";
			cin >> p;
			cout << "What is the interest rate?\n";
			cin >> ir;
			ir = ir / 100;
			cout << "How many years has it been?\n";
			cin >> t;
			cout << endl;
			si = p * ir * t;
			cout << "The simple interest is $" << si << endl;
		}
		else if (mnuc == 6)
		{
			cout << "What is the voltage?\n";
			cin >> v;
			cout << "What is the resistance?\n";
			cin >> r;
			cout << endl;
			i = v / r;
			cout << "The current is " << i << " amps";
		}
		else if (mnuc == 7)
		{
			cout << "What is the mass of the object?\n";
			cin >> m;
			cout << "What is the acceleration in meters/second of the object?\n";
			cin >> a;
			cout << endl;
			f = m * a;
			cout << "The force of the object is " << f << " Newtons\n";
		}
		else if (mnuc == 8)
		{
			cout << "What is the mass of the object?\n";
			cin >> m;
			e = m * 299792458 * 299792458;
			cout << endl;
			cout << "The energy is " << e << endl;
		}
		else if (mnuc == 9)
		{
			cout << "What is the spped you were traveling at?\n";
			cin >> s;
			cout << endl;
			if (s > 79)
			{
				fee = (s - 80) * 10 + 500;
				cout << "Your speeding ticket is $" << fee << endl;
			}
			else
			{
				cout << "You did not go fast enought to get a speeding ticket.";
			}
		}
		else if (mnuc == 10)
		{
			cout << "What is the length?\n";
			cin >> len;
			cout << "What is the tempurature in celcius?\n";
			cin >> temp;
			cout << endl;
			c = 0.0000116 * (temp - 20) * len;
			nlen = len + c;
			cout << "The new length is " << nlen << endl;
		}

		// asks user to run program again
		cout << endl;
		cout << "Would you like to run program again?(y/n)\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

