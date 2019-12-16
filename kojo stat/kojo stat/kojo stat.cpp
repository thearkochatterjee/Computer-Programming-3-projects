// kojo stat
// programmer: Arko Chatterjee
//
// Purpose: edit partner's code and make it work

#include "stdafx.h"
#include "stats.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	char ans;
	int lr;
	int hr;
	int nnum;
	stats c;
	string line; // word input
	ifstream myfile("numlist.txt"); // path
	int arrn[101];
	int i;
	system("color 30");
	do
	{
		c.stat();
		if (myfile.is_open())
		{
			i = 0;
			while (getline(myfile, line))
			{
				i++;
				istringstream buffer(line);
				buffer >> arrn[i];
			}
			myfile.close();
		}
		else cout << "Unable to open file\n";
		nnum = i;
		cout << "Orginal Array:\n";
		c.stat(arrn, nnum);
		cout << c.arrtostring(nnum);
		cout << "Sort:\n";
		c.sort(nnum);
		cout << c.arrtostring(nnum);
		cout << "Mean:\n";
		c.mean(nnum);
		cout << c.tostring();
		cout << "Median:\n";
		c.median(nnum);
		cout << c.tostring();
		cout << "Min:\n";
		c.findmin();
		cout << c.tostring();
		cout << "Max:\n";
		c.findmax(nnum);
		cout << c.tostring();
		cout << "Length of File:\n";
		cout << nnum << endl;
		cout << "Do you want to run again?\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}
