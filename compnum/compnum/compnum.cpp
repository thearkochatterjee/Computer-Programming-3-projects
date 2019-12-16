// compnum
// Programmer: Arko Chatterjee
//
// Purpose: make caluclations using complex numbers

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include "calculator.h"
using namespace std;
void add(double real, double imagine, double real2, double imagine2);
void subtract(double real, double imagine, double real2, double imagine2);
void mult(double real, double imagine, double real2, double imagine2);
void divide(double real, double imagine, double real2, double imagine2);
void power(double real, double imagine, double real2, double imagine2);
void sqrt(double real, double imagine);
void abs(double real, double imagine);

void add(double real, double imagine, double real2, double imagine2)
{
	calculator comp(real, imagine, real2, imagine2);
	comp.setcomp(real, imagine);
	comp.setcomp2(real2, imagine2);
	comp.addreal();
	comp.addimagine();
	cout << "Addition:\n";
	if (comp.getimaginer() < 0)
	{
		cout << endl << "The answer is " << comp.getrealr() << " " << comp.getimaginer() << "i\n";
	}
	else
	{
		cout << endl << "The answer is " << comp.getrealr() << " + " << comp.getimaginer() << "i\n";
	}
}
void subtract(double real, double imagine, double real2, double imagine2)
{
	calculator comp(real, imagine, real2, imagine2);
	comp.setcomp(real, imagine);
	comp.setcomp2(real2, imagine2);
	comp.subtractreal();
	comp.subtractimagine();
	cout << "Subtraction:\n";
	if (comp.getimaginer() < 0)
	{
		cout << endl << "The answer is " << comp.getrealr() << " " << comp.getimaginer() << "i\n";
	}
	else
	{
		cout << endl << "The answer is " << comp.getrealr() << " + " << comp.getimaginer() << "i\n";
	}
}
void mult(double real, double imagine, double real2, double imagine2)
{
	calculator comp(real, imagine, real2, imagine2);
	comp.setcomp(real, imagine);
	comp.setcomp2(real2, imagine2);
	comp.multreal();
	comp.multimagine();
	cout << "Multipication:\n";
	if (comp.getimaginer() < 0)
	{
		cout << endl << "The answer is " << comp.getrealr() << " " << comp.getimaginer() << "i\n";
	}
	else
	{
		cout << endl << "The answer is " << comp.getrealr() << " + " << comp.getimaginer() << "i\n";
	}
}
void divide(double real, double imagine, double real2, double imagine2)
{
	double nnreal;
	double nnimagine;
	double dnreal;
	double dnimagine;
	double con;
	con = imagine2 * -1;
	calculator comp(real, imagine, real2, imagine2);
	comp.setcomp(real, imagine);
	comp.setcomp2(real2, con);
	comp.multreal();
	comp.multimagine();
	nnreal = comp.getrealr();
	nnimagine = comp.getimaginer();
	comp.setcomp(real2, imagine2);
	comp.setcomp2(real2, con);
	comp.multreal();
	comp.multimagine();
	dnreal = comp.getrealr();
	dnimagine = comp.getimaginer();
	comp.setdcomp(nnreal, nnimagine);
	comp.setdcomp2(dnreal, dnimagine);
	comp.dividereal();
	comp.divideimagine();
	cout << "Divide:\n";
	if (comp.getimaginer() < 0)
	{
		cout << endl << "The answer is " << comp.getrealr() << " " << comp.getimaginer() << "i\n";
	}
	else
	{
		cout << endl << "The answer is " << comp.getrealr() << " + " << comp.getimaginer() << "i\n";
	}
}
void power(double real, double imagine)
{
	int power;
	double rreal;
	double rimagine;
	double nr;
	double ni;
	cout << "Powers:\n";
	cout << "To what power do you want to multiply the compex number?\n";
	cin >> power;
	rreal = 0;
	rimagine = 0;
	nr = real;
	ni = imagine;
	if (power > 0)
	{
		for (int i = 1; i <= power - 1; i++)
		{
			if (i != 1)
			{
				nr = rreal;
				ni = rimagine;
			}
			calculator comp(nr, ni, real, imagine);
			comp.setcomp(nr, ni);
			comp.setcomp2(real, imagine);
			comp.multreal();
			comp.multimagine();
			rreal = comp.getrealr();
			rimagine = comp.getimaginer();
		}
		if (rimagine < 0)
		{
			cout << "The answer is " << rreal << " " << rimagine << "i\n";
		}
		else
		{
			cout << "The answer is " << rreal << " + " << rimagine << "i\n";
		}
	}
	else if (power == 0)
	{
		cout << "The answer is 1\n";
	}
	else
	{
		power = power * -1;
		for (int i = 1; i <= power - 1; i++)
		{
			if (i > 1)
			{
				real = rreal;
				imagine = rimagine;
			}
			calculator comp(real, imagine, real, imagine);
			comp.setcomp(real, imagine);
			comp.setcomp2(real, imagine);
			comp.multreal();
			comp.multimagine();
			rreal = comp.getrealr();
			rimagine = comp.getimaginer();
		}
		if (rimagine < 0)
		{
			cout << "The answer is 1 / " << rreal << " " << rimagine << "i\n";
		}
		else
		{
			cout << "The answer is 1 / " << rreal << " + " << rimagine << "i\n";
		}
	}
}
void sqrt(double real, double imagine)
{
	double rreal;
	double rimagine;
	rreal = 0;
	rimagine = 0;
	rreal = (1 / sqrt(2)) * (sqrt(sqrt((real * real) + (imagine * imagine)) + real));
	rimagine = imagine / (2 * rreal);
	cout << "Squareroot:\n";
	cout << "The answer is " << rreal << " + " << rimagine << "i\n";
}
void abs(double real, double imagine)
{

}
void input()
{
	char sign;
	char sign2;
	char op;
	int rt;
	double real;
	double imagine;
	double real2;
	double imagine2;
	real = 0;
	imagine = 0;
	real2 = 0;
	imagine2 = 0;
	sign2 = '+';
	cout << "What is the first complex number?\n";
	cin >> real >> sign >> imagine;
	cout << "What function do you want to use?\n";
	cin >> op;
	if ((op != '^') && (op != 'r'))
	{
		cout << "What is the second complex number?\n";
		cin >> real2 >> sign2 >> imagine2;
	}
	if (sign == '-')
	{
		imagine = imagine * -1;
	}
	if (sign2 == '-')
	{
		imagine2 = imagine2 * -1;
	}
	if (op == '+')
	{
		add(real, imagine, real2, imagine2);
	}
	else if (op == '-')
	{
		subtract(real, imagine, real2, imagine2);
	}
	else if (op == '*')
	{
		mult(real, imagine, real2, imagine2);
	}
	else if (op == '/')
	{
		divide(real, imagine, real2, imagine2);
	}
	else if (op == '^')
	{
		power(real, imagine);
	}
	else if (op == 'r')
	{
		sqrt(real, imagine);
	}
	else if (op == 'a')
	{
		add(real, imagine, real2, imagine2);
		subtract(real, imagine, real2, imagine2);
		mult(real, imagine, real2, imagine2);
		divide(real, imagine, real2, imagine2);
		power(real, imagine);
		sqrt(real, imagine);
	}
}
int main()
{
	char ans;
	system("color 30");
	do
	{
		input();
		cout << "Do you want to run again?\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}