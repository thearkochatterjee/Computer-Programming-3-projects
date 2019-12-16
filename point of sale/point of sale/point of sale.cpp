// point of sale
// programmer: arko chatterjee
//
// purpose:

#include "stdafx.h"
#include <iostream>
using namespace std; // needed for cin and cout

void welcome()
{
	cout << "Welcome to the Snack Bar\n";
	cout << "What would you like to order?\n";
}
void dismenu()
{
	cout << "S - Snadwich $4.99\n";
	cout << "C - Chips $2.99\n";
	cout << "B - Brownie $0.50\n";
	cout << "R - Regular Drink $1.00\n";
	cout << "L - Large Drink $2.00\n";
	cout << "X - Cancel sale and start over\n";
	cout << "T - Total the sale\n";
}
int menu(int item, int t)
{
	int titem;
	titem = t;
	if ((item == 's') || (item == 'c') || (item == 'b') || (item == 'r') || (item == 'l'))
	{
		titem++;
	}
	return titem;
}
void output(float total, int snum, int cnum, int bnum, int rnum, int lnum, int t)
{
	cout << "Your total cost is $" << total << endl << endl;
	cout << "Amount of Sandwiches: " << snum << endl;
	cout << "Amount of Chips: " << cnum << endl;
	cout << "Amount of Brownies: " << bnum << endl;
	cout << "Amount of Regular Drinks: " << rnum << endl;
	cout << "Amount of Large Drinks: " << lnum << endl;
	cout << "Total amount of items you bought: " << t << endl;
}

int main()
{
	// declare varibles
	char ans; //run program again
	float total; // total cost for purchase
	char item;
	int snum;
	int cnum;
	int bnum;
	int rnum;
	int lnum;
	int titem;
	int t;

	// color
	system("color 03");

	// loop program again
	do
	{
		// intalize
		t = 0;
		total = 0;
		snum = 0;
		cnum = 0;
		bnum = 0;
		rnum = 0;
		lnum = 0;

		// loop for menu
		welcome();
		do
		{
			// input
			dismenu();
			cin >> item;
			cout << endl;

			// arithmetic
			t = menu(item, t);
			if ((item == 's') || (item == 'S'))
			{
				total = total + 4.99;
				snum++;
			}
			else if ((item == 'c') || (item == 'C'))
			{
				total = total + 2.99;
				cnum++;
			}
			else if ((item == 'b') || (item == 'B'))
			{
				total = total + 0.5;
				bnum++;
			}
			else if ((item == 'r') || (item == 'R'))
			{
				total = total + 1;
				rnum++;
			}
			else if ((item == 'l') || (item == 'L'))
			{
				total = total + 2;
				lnum++;
			}
			else if ((item == 'x') || (item == 'X'))
			{
				total = 0;
				cout << "You have reset yoour purchase\n";
			}
		} while (item != 't');
		
		// output
		output(total, snum, cnum, bnum, rnum, lnum, t);

		// run program again
		cout << endl;
		cout << "Do you want to run this program again(y/n)?\n";
		cin >> ans;
		cout << endl;
	} while (ans == 'y');
	return 0;
}

