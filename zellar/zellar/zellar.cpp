// zellar
// programmer: Arko Chatterjee
//
// Purpose: Show the day of the week a certain day is

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char ans;
	int k; // day of the month
	int m; // month number starts on march ends on febuary
	int d; // last two dights of the year
	int c; // first two dights of the year
	int f;
	int r;
	do
	{
		cout << "What is the day of the month?\n";
		cin >> k;
		cout << "What is the month number (march=1, feb=12)?\n";
		cin >> m;
		cout << "What is the first two dights of the year?\n";
		cin >> c;
		cout << "What is the last two dights of the year?\n";
		cin >> d;
		if ((m == 11) | (m == 12))
		{
			if (((c%4)==0) && (d==0) && (c > 9))
			{
				d = d - 2;
			}
			else if (c>9)
			{
				d = d - 1;
			}
			else if (c<5)
			{
				d = d - 2;
			}
			else
			{
				d = d + 4;
			}
		}
		if (c < 5)
		{
			d++;
		}
		else if (c < 10)
		{
			d = d + 4;
		}
		c = c % 4;
		f = k + ((13 * m - 1) / 5) + d + (d / 4) + (c / 4) - 2 * c;
		r = f - 7 * (f / 7);
		cout << "The day is ";
		if (r == 1)
		{
			cout << "Monday";
		}
		if (r == 2)
		{
			cout << "Tuesday";
		}
		if (r == 3)
		{
			cout << "Wednesday";
		}
		if (r == 4)
		{
			cout << "Thursday";
		}
		if (r == 5)
		{
			cout << "Friday";
		}
		if (r == 6)
		{
			cout << "Saturday";
		}
		if (r == 0)
		{
			cout << "Sunday";
		}
		cout << endl;
		cout << "Do you want to run program again?\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

