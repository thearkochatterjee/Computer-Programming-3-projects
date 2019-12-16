#include "stdafx.h"
#include "calculator.h"

calculator::calculator()
{
	nreal = 0;
	nimagine = 0;
	nreal2 = 0;
	nimagine2 = 0;
	nrealr = 0;
	nimaginer = 0;
}
calculator::calculator(double real, double imagine, double real2, double imagine2)
{
	nreal = real;
	nimagine = imagine;
	nreal2 = real2;
	nimagine2 = imagine2;
}
calculator::~calculator()
{

}
double calculator::getreal()
{
	return nreal;
}
double calculator::getimagine()
{
	return nimagine;
}
double calculator::getreal2()
{
	return nreal2;
}
double calculator::getimagine2()
{
	return nimagine2;
}
double calculator::getrealr()
{
	return nrealr;
}
double calculator::getimaginer()
{
	return nimaginer;
}
void calculator::setcomp(double real, double imagine)
{
	nreal = real;
	nimagine = imagine;
}
void calculator::setcomp2(double real2, double imagine2)
{
	nreal2 = real2;
	nimagine2 = imagine2;
}
void calculator::setdcomp(double nnreal, double nnimagine)
{
	nreal = nnreal;
	nimagine = nnimagine;
}
void calculator::setdcomp2(double dnreal, double dnimagine)
{
	nreal2 = dnreal;
	nimagine2 = dnimagine;
}
double calculator::addreal()
{
	nrealr = nreal + nreal2;
	return(nrealr);
}
double calculator::addimagine()
{
	nimaginer = nimagine + nimagine2;
	return(nimaginer);
}
double calculator::subtractreal()
{
	nrealr = nreal - nreal2;
	return(nrealr);
}
double calculator::subtractimagine()
{
	nimaginer = nimagine - nimagine2;
	return(nimaginer);
}
double calculator::multreal()
{
	nrealr = nreal * nreal2;
	nrealr = nrealr + (nimagine * nimagine2 * -1);
	return(nrealr);
}
double calculator::multimagine()
{
	nimaginer = nreal * nimagine2;
	nimaginer = nimaginer + (nreal2 * nimagine);
	return(nimaginer);
}
double calculator::dividereal()
{
	nrealr = nreal / nreal2;
	return(nrealr);
}
double calculator::divideimagine()
{
	nimaginer = nimagine / nreal2;
	return(nimaginer);
}
double calculator::absreal()
{

	return(nrealr);
}
double calculator::absimagine()
{

	return(nimaginer);
}