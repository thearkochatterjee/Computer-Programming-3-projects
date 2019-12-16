// electric
// Programmer: Arko Chatterjee
//
// Purpose: calculates the amount of money you pay for electricity and shows the date and time

#include "stdafx.h"
#include <time.h> // needed to show time
#include <iostream> // needed to make the program run
#include <iomanip>// needed for rounding numbers
using namespace std; // necessary for using cin and cout

//varible declaration
int kwh; // kilowatt hours used provided by the user
float br; // shows the base rate for exspense
float sc;// shows the surcharge fee
float ct;// shows the citytax
float pay;// shows the payment amount if paid on time
float lpay;// shows the payment amount if paid late
char ans; // used for repeat

int _tmain(int argc, _TCHAR* argv[])
{
	// changes color of the form
	system("color 30");

	// loop makes user run the program more than once
	do
	{
		// ask user for input
		cout << "Enter Amount of Kilowatt Hours used: ";
		cin >> kwh;

		//calculates base rate
		br = kwh * 0.0475;

		//calculates surchage fee
		sc = br * 0.1;

		//calculates city tax
		ct = br * 0.03;

		// calculates total payment amount
		pay = br + sc + ct;

		// calculates late payment amount
		lpay = pay * 1.04;

		//rounds data
		cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

		//time and date
		time_t currentTime;

		// get the current time
		time(&currentTime); // fill now with the current time
		struct tm * ptm = localtime(&currentTime);

		//output data in handout form
		cout << endl;
		cout << "        C O M P S C I  Electric " << endl;
		cout << "--------------------------------------" << endl;
		cout << "Kilowatt used " << kwh << endl;
		cout << "--------------------------------------" << endl;
		cout << endl;

		// outputs the base rate
		cout << setiosflags(ios::left) << setfill(' ') << "Base Rate " << resetiosflags(ios::left) << setw(5) << kwh << resetiosflags(ios::left) << setw(2) << "   @ 0.0475";
		cout << setiosflags(ios::right) << setw(7) << " $ " << br << endl;
		
		// outputs the surcharge
		cout << "Surcharge " << setiosflags(ios::right) << setw(24) << " $ " << sc << endl;

		// outputs the citytax
		cout << "Citytax " << resetiosflags(ios::left) << setw(26) << " $ " << ct << endl;
		cout << setiosflags(ios::left) << setw(38) << "______" << endl;

		//outputs time and date
		cout << endl;
		cout << "It is now " << ctime(&currentTime);
		cout << "Today is " << ((ptm->tm_mon) + 1) << "/";
		cout << ptm->tm_mday << "/";
		cout << ptm->tm_year << endl;
		cout << endl;

		// output total payment and late payment
		cout << "Pay this amount:" << setw(17) << "$" << pay << endl;
		cout << endl;
		cout << "After 20 days Pay:" << setw(15) << "$" << lpay << endl;
		cout << endl;

		// ask user if they want to run again
		cout << "Do you want to run again (Y/N)?\n";
		cout << "You must type a 'Y' or an 'N'.\n";
		cin >> ans;
	} while ((ans == 'Y') | (ans == 'y'));
	return 0;
}

