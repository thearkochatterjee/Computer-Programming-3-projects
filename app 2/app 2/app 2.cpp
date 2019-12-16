// app 2.cpp : Defines the entry point for the console application.
// Programmer: Arko Chatterjee
//
// Purpose:

#include "stdafx.h"
#include <iostream>
using namespace std; // necessary for using cin and cout

// varible declarations
float wait;
float num1;
float num2;
float ans;
char op;

int main()
{
	//ask user for input
	cout << "What is your first number? ";
	cin >> num1;
	cout << "What is your second number? ";
	cin >> num2;
	cout << "What operation do you want to use? ";
	cin >> op;

	//test what operation is asked for
	if( op = '+')
	{
		ans=num1+num2;
	}

	//output data
	cout << "Your answer is " << ans << '\n';
	cin >> wait;
	return 0;
	}
