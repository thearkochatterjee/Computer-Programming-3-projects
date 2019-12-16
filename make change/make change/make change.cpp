// make change
// Programmer: Arko Chatterjee
//
// Purpose: Find the change of a payment

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;
 
// declare varibles
float pp; //price of purchase
float ar; //amount recieved
float cd; // change due
float v100d; // value of one hundred dollar
int a100d; // amount of one hundred dollar
float v50d; // value of fifty dollar
int a50d; // amount of fifty dollar
float v20d; // value of twenty dollar
int a20d; // amount of twenty dollar
float v10d; // value of ten dollar
int a10d; // amount of ten dollar
float v5d; // value of five dollar
int a5d; // amount of five dollar
float vd; // value of dollars
int ad; // amount of dollars
float vq; // value of quarters
int aq; // amount of quarters
float vdi; // value of dimes
int adi; // amount of dimes
float vn; // value of nickels
int an; // amount of nickels
float vp; // value of pennies
int ap; // amount of pennies
char ans; // used for looping
char ans2; // asks user if they want to keep ordering
float rem;
int cd2; // interger version of change
int lo; // left over
int lo2;
int mnu; // menu choice
int inmth; // price of purchase input method
char e;

int _tmain(int argc, _TCHAR* argv[])
{
	system("color 30");
	do
	{
		// ask user for input
		cout << "Welcome to Raja India Sir\n";
		cout << "What do you order?\n";
		cout << "Do you want to order or do you want to enter purcahse price manually?\n";
		cout << "Enter 1 if you want to enter in purchase manually.\n";
		cout << "Enter 2 if you want to order from menu.\n";
		cin >> inmth;
		if (inmth == 1)
		{
			cout << "Enter Price of Purchase:  $";
			cin >> pp;
		}
		if (inmth == 2)
		{
			pp = 0;
			cout << endl;
			cout << "If you want to stop ordering enter a different key from the ones shown below.\n";
			cout << endl;
			cout << "Press 1 for Fried Chicken           - $10.00\n";
			cout << "Press 2 for Fish Tikka              - $20.00\n";
			cout << "Press 3 for Goat Curry              - $20.00\n";
			cout << "Press 4 for Lamb Korma              - $20.00\n";
			cout << "Press 5 for Chicken Tikka Masala    - $15.00\n";
			cout << "Press 6 for Paratha                  - $7.50\n";
			cout << "Press 7 for Chili Chicken            - $5.99\n";
			cout << "Press 8 for Tikka Bartha             - $9.99\n";
			cout << "Press 9 for Gulab Jamun              - $5.99\n";
			cout << "Press 10 for Kheer                  - $29.99\n";
			do
			{
				cin >> mnu;
				if (mnu == 1)
				{
					pp += 10;
				}
				else if (mnu == 2)
				{
					pp += 20;
				}
				else if (mnu == 3)
				{
					pp += 20;
				}
				else if (mnu == 4)
				{
					pp += 20;
				}
				else if (mnu == 5)
				{
					pp += 15;
				}
				else if (mnu == 6)
				{
					pp += 7.5;
				}
				else if (mnu == 7)
				{
					pp += 5.99;
				}
				else if (mnu == 8)
				{
					pp += 9.99;
				}
				else if (mnu == 9)
				{
					pp += 5.99;
				}
				else if (mnu == 10)
				{
					pp += 29.99;
				}
				else
				{
					cout << "Are you sure you want to stop ordering?\n";
					cout << "y for yes, n for no\n";
					cin >> e;
				}
				cout << "Your current price of purchase is" << setw(9) << "$" << pp << endl;
				//cout << "Is there anything else you would like to order?\n";
				//cout << "press y for yes or n for no\n";
				//cin >> ans2;
			} while (e != 'y');
		}
		cout << "Enter Amount receieved:   $";
		cin >> ar;
		if (ar < pp)
		{
			do
			{
				cout << "You need to pay more money for purchase.\n";
				cout << "Enter Amount received: ";
				cin >> ar;
			} while (ar < pp);
		}
		// calculates change
		cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
		cd = ar - pp;
		cd2 = cd * 100;
		lo = cd2 % 10000;
		a100d = (cd2 - lo) / 10000;
		lo2 = lo % 5000;
		a50d = (lo - lo2) / 5000;
		lo = lo2 % 2000;
		a20d = (lo2 - lo) / 2000;
		lo2 = lo % 1000;
		a10d = (lo - lo2) / 1000;
		lo = lo2 % 500;
		a5d = (lo2 - lo) / 500;
		lo2 = lo % 100;
		ad = (lo - lo2) / 100;
		lo = lo2 % 25;
		aq = (lo2 - lo) / 25;
		lo2 = lo % 10;
		adi = (lo - lo2) / 10;
		lo = lo2 % 5;
		an = (lo2 - lo) / 5;
		lo2 = lo % 1;
		ap = (lo - lo2) / 1;
		v100d = a100d * 100;
		v50d = a50d * 50;
		v20d = a20d * 20;
		v10d = a10d * 10;
		v5d = a5d * 5;
		vd = ad * 1;
		vq = aq * 0.25;
		vdi = adi * 0.1;
		vn = an * 0.05;
		vp = ap * 0.01;

		// output data
		cout << "Change Due:" << setiosflags(ios::right) << setw(17) << "$" << cd << endl;
		cout << "-----------------------------------------\n";
		cout << "Hundred Dollar:" << setw(5) << a100d << setw(10) << v100d << endl;
		cout << "Fifty Dollar" << setw(8) << a50d << setw(10) << v50d << endl;
		cout << "Twenty Dollar:" << setw(6) << a20d << setw(10) << v20d << endl;
		cout << "Ten Dollar:" << setw(9) << a10d << setw(10) << v10d << endl;
		cout << "Five Dollar:" << setw(8) << a5d << setw(10) << v5d << endl;
		cout << "Dollars:" << setw(12) << ad << setw(10) << vd << endl;
		cout << "Quearters:" << setw(10) << aq << setw(10) << vq << endl;
		cout << "Dimes:" << setw(14) << adi << setw(10) << vdi << endl;
		cout << "Nickel:" << setw(13) << an << setw(10) << vn << endl;
		cout << "Pennies:" << setw(12) << ap << setw(10) << vp << endl;
		cout << "-----------------------------------------\n";
		cout << endl;
		cout << "Change Total:" << setw(11) << "$" << cd << endl;

		

		// repeats the program
		cout << endl;
		cout << "Do you want to run this program again?" << endl;
		cout << "Type in y for yes or n for no" << endl;
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

