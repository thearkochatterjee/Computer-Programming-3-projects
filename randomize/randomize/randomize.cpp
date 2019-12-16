// randomize.cpp : Defines the entry point for the console application.
// programmer: arko chatterjee
//
// prupose: randomize numbers and finds the average

#include "stdafx.h"
#include <iostream>
using namespace std; // needed for cin and cout

int rnum(int min, int dif)
{
	int rnum;
	rnum = (int)(rand() % dif);
	rnum = rnum + min;
	return rnum;
}

int main()
{
	// declare varibles
	char ans; // needed to run program again
	int i; // counter
	int arrnum[100000]; // array of numbers
	float avg; // average
	int arnum; // amount of random numbers
	int min; // minimum value for random
	int max; // maxium value for random
	int temp; // temporary value
	int dif; // difference between min and max

	// change gui color
	system("color 03");

	// loop to run program again
	do
	{
		//intalize
		i = 0;
		avg = 0;
		arnum = 0;

		//input
		cout << "How many numbers would you like to randomly generate?\n";
		cin >> arnum;
		cout << "What would you like for the minimum value to be?\n";
		cin >> min;
		cout << "What would you like for the maxium value to be?\n";
		cin >> max;

		//arithmetic
		arnum++;
		dif = (max - min) + 1;
		for (int i = 1; i < arnum; i++)
		{
			arrnum[i] = rnum(min, dif);
			avg = avg + arrnum[i];
		}
		temp = 0;
		for (int i = 1; i < arnum - 1; i++)
		{
			for (int j = i + 1; j < arnum; j++)
			{
				if (arrnum[i] > arrnum[j])
				{
					temp = arrnum[i];
					arrnum[i] = arrnum[j];
					arrnum[j] = temp;
				}
			}
		}

		// output
		cout << endl;
		cout << "These are the randomly generated numbers:\n";
		i = 1;
		do
		{
			cout << arrnum[i] << endl;
			i++;
		} while (i <= arnum - 1);
		avg = avg / arnum;
		cout << endl;
		cout << "The average of all values is " << avg << endl;

		// run program again
		cout << endl;
		cout << "Do you want to run again(y/n)?\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

