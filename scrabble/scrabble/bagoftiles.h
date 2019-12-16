#ifndef _BAGOFTILES_H
#define _BAGOFTILES_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include "tile.h"
using namespace std;

class bagoftiles
{
public:
	bagoftiles();
	bagoftiles(tile t[]);
	tile gett(int t);
	void sett(int i, tile t);
	void gettiles();
	void shuffle();
private:
	tile myt[100];
};

bagoftiles::bagoftiles()
{
	for (int i = 0;i < 100;i++){
		myt[i].getl() = "";
	}
}
bagoftiles::bagoftiles(tile t[])
{
	for (int i = 0;i < 100;i++) {
		myt[i] = t[i];
	}
}
tile bagoftiles::gett(int t)
{
	return myt[t];
}
void bagoftiles::sett(int i, tile t)
{
	myt[i] = t;
}
void bagoftiles::gettiles()
{
	string line, sscore;
	int i = 0, freq;
	ifstream myfile("tiles.txt");
	if (myfile.is_open())
	{
		int n = 0;
		while (getline(myfile, line))
		{
			istringstream buffer(line.substr(3, 2));
			buffer >> freq;
			while (i < freq) {
				myt[n].setl(line.substr(0, 1));
				int value;
				istringstream buffer(line.substr(1, 2));
				buffer >> value;
				myt[n].setv(value);
				n++;
				i++;
			}
			i = 0;
		}
		myfile.close();
	}
}
void bagoftiles::shuffle()
{
	srand((unsigned)time(NULL));
	int r;
	tile temp;
	for (int i = 0;i < 100;i++) {
		r = (rand() % 100);
		temp = myt[r];
		myt[r] = myt[i];
		myt[i] = temp;
	}
}
#endif