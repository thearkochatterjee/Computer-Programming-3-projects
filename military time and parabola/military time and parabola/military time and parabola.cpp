// military time
// Programmer: Arko Chatterjee
//
// Purpose: reads times in military format and outputs number of hours between two times
// find roots of a quadratic equation
// find slope of a line

#include "stdafx.h"
#include <iomanip>
#include <Windows.h>
#include <iostream>
using namespace std; // needed for using cin and cout

int _tmain(int argc, _TCHAR* argv[])
{
	//varible declaration
	char ans; // used to run propgram again
	double a; // a value for quadratic equation
	double b; // b value for quadratic equation
	double c; // c value for quadratic equation
	double na; // new a value for quadratic equation
	double nb; // new b value for quadratic equation
	double nc; // new c value for quadratic equation
	double r1; // root value for quadratic
	double r2; // root value for quadratic
	double x1; // x1 value
	double y1; // y1 value
	double x2; // x2 value
	double y2; // y2 value
	double slope; // slope of two points
	double yi; // y-interception of line from two points
	double x1pi; // x1 point of interception
	double y1pi; // y1 point of interception
	double x2pi; // x2 point of interception
	double y2pi; // y2 point of interception
	double sqrv; // square root value
	int i; // flag for imaginary root
	int ftime; // first time
	int stime; // second time
	int hours;
	int mins;
	int fthr;
	int ftmin;
	int sthr;
	int stmin;

	do
	{
		system("color 30");
		cout << "Military Time\n";
		// ask for input from user for military time
		cout << "Enter First Time: ";
		cin >> ftime;
		if (((ftime % 100) > 60) | (ftime>2400))
		{
			do
			{
				cout << "Time was invalid.\n";
				cout << "Make sure it is under 60min and under 24 hours\n";
				cout << "Enter First Time: ";
				cin >> ftime;
			} while (((ftime % 100) > 60) | (ftime>2400));
		}
		cout << "Enter Second Time: ";
		cin >> stime;
		if (((stime % 100) > 60) | (stime>2400))
		{
			do
			{
				cout << "Time was invalid.\n";
				cout << "Make sure it is under 60min and under 24 hours\n";
				cout << "Enter First Time: ";
				cin >> stime;
			} while (((stime % 100) > 60) | (stime>2400));
		}

		// arithmetic for military time
		ftmin = ftime % 100;
		fthr = (ftime - ftmin) / 100;
		stmin = stime % 100;
		sthr = (stime - stmin) / 100;
		if (fthr > sthr)
		{
			sthr = sthr + 24;

		}
		if (ftmin > stmin)
		{
			sthr--;
			stmin = stmin + 60;
		}
		hours = sthr - fthr;
		mins = stmin - ftmin;

		// output for military time
		cout << hours << " hours " << mins << " minutes\n";

		// run program again for military time
		cout << "Do you want to run program again?\n";
		cout << "y for yes, n for no\n";
		cin >> ans;
	} while (ans == 'y');

	//quratic and linear
	ans = 'n';
	system("color 03");
	do
	{
		cout << "Quadratic Formula and Linear Equation\n";
		// ask input for user for quadtratic
		cout << "Enter A, B, and C values: ";
		cin >> a >> b >> c;
		cout << endl << "Values will be rounded to nearest hundreth\n";

		// arrithmetic for quadratic
		cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
		i = 0;
		if (a == 0)
		{
			do
			{
				cout << "A cannot equal zero\n";
				cout << "enter in a different number for a\n";
				cin >> a;
			} while (a == 0);
		}
		sqrv = b*b - 4 * a*c;
		if (sqrv < 0)
		{
			sqrv = sqrv * -1;
			i = 1;
		}
		r1 = (-b + sqrt(sqrv)) / 2 * a;
		r2 = (-b - sqrt(sqrv)) / 2 * a;

		// out put for quadratic
		if (i == 1)
		{
			cout << "The roots are: " << r1 << "i " << " and " << r2 << "i" << endl;
		}
		else if (i == 0)
		{
			cout << "The roots are: " << r1 << " and " << r2 << endl;
		}
		cout << endl;
		i = 0;

		// ask user for input
		cout << "Enter X1 and Y1: ";
		cin >> x1 >> y1;
		cout << "Enter X2 and Y2: ";
		cin >> x2 >> y2;
		cout << endl;

		// arrithmetic
		slope = (y2 - y1) / (x2 - x1);
		yi = y1 - slope * x1;
		na = a;
		nb = b - slope;
		nc = c - yi;
		sqrv = nb * nb - 4 * na * nc;

		// output data
		cout << "Slope:             " << slope << endl;
		cout << "Y-intercept:       " << yi << endl;
		cout << endl;
		if (sqrv < 0)
		{
			cout << "Point of intersection does not exsist.\n";
		}
		else
		{
			x1pi = (-nb + sqrt(sqrv)) / (2 * na);
			y1pi = slope * x1pi + yi;
			x2pi = (-nb - sqrt(sqrv)) / (2 * na);
			y2pi = slope * x2pi + yi;
			cout << "The points of intersection: " << "(" << x1pi << "," << y1pi << ")" << " and (" << x2pi << "," << y2pi << ")" << endl;
		}

		// run program again for quadratic
		cout << "Do you wan to run program again?\n";
		cout << "y for yes, n for no\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}
