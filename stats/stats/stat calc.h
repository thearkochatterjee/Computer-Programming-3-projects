#include <iostream>
#include <random>
#include <sstream>
using namespace std;

#ifndef stat_h
#define stat_h
class stat
{
public:
	// defualt constructor
	void setnums();

	// fill constructor
	void setnums(int non, double min, double max);

	// accessor funtions
	double getrange();
	double getmode();
	double getmedian();
	double getmean();
	void getfunum();
	void getarrnum();

	// member functions
	void genarrnum();
	double mode();
	double mean();
	double median();
	void funum();
	void shuffle();
	string tostring();
private:
	int arrnum[100];
	int mynon;
	int arrunum[100];
	int mymin, mymax, rge;
	double ans;
};
#endif