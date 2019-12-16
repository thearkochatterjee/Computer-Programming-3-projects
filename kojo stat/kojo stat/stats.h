#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

#ifndef stats_h
#define stats_h
class stats
{
public:
	void stat();
	void stat(int arrn[], int nnum);
	int findlength(int nnum);
	int findmax(int nnum);
	int findmin();
	double mean(int nnum);
	void sort(int nnum);
	int median(int nnum);
	string tostring();
	string arrtostring(int nnum);
private:
	int arrnums[100];
	double ans;
};
#endif