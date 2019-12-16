#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

#ifndef dshape_h
#define dshape_h
class dshape
{
public:
	void setpoints(double x[], double y[]);
	double finddis();
	double findper();
	double findarea();
	double getdis();
	double getper();
	double getarea();
	string tostring();
private:
	double myx[4];
	double myy[4];
	double dis[4];
	double per;
	double area;
};
#endif