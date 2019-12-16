// stats
// programmer: arko chatterjee
//
// purpose: have an array of numbers, find the mean, median, mode, and range

#include "stdafx.h"
#include <iostream>
#include "stat calc.h"
using namespace std;
void input();

void input()
{
	int non;
	int min;
	int max;
	stat s;
	int v;
	cout << "How many numbers would you like to use?\n";
	cin >> non;
	do
	{
		cout << "What is the min?\n";
		cin >> min;
		cout << "What is the max?\n";
		cin >> max;
	} while (max < min);
	cout << "What would you like to view?\n";
	cout << "1 - mean\n";
	cout << "2 - median\n";
	cout << "3 - mode\n";
	cout << "4 - range\n";
	cout << "5 - find unique numbers\n";
	cout << "6 - shuffle\n";
	cin >> v;
	s.setnums(non, min, max);
	s.genarrnum();
	if (v == 1)
	{
		s.mean();
	}
	if (v == 2)
	{
		s.median();
	}
	if (v == 3)
	{
		s.mode();
	}
	if (v == 4)
	{
		s.getrange();
	}
	if (v == 5)
	{
		s.funum();
	}
	if (v == 6)
	{
		s.shuffle();
	}
}
int main()
{
	char ans;
	do
	{
		input();
		cout << "Do you want to run again?\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

