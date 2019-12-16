//header
#include "stdafx.h"
#include <iostream>

using namespace std;

#ifndef calculator_h
#define calculator_h

class calculator
{
public:
	// default constructor
	calculator();

	// overload constructor
	calculator(double, double, double, double);

	// destructor
	~calculator();

	// accessor functions
	double getreal();
	double getimagine();
	double getreal2();
	double getimagine2();
	double getrealr();
	double getimaginer();

	//mutator function
	void setcomp(double, double);
	void setcomp2(double, double);
	void setdcomp(double, double);
	void setdcomp2(double, double);
	double addreal();
	double addimagine();
	double subtractreal();
	double subtractimagine();
	double multreal();
	double multimagine();
	double dividereal();
	double divideimagine();
	double absreal();
	double absimagine();

private:
	// member varibles
	double nreal;
	double nreal2;
	double nimagine;
	double nimagine2;
	double nrealr;
	double nimaginer;
};

#endif