#ifndef _TOPTEN_H
#define _TOPTEN_H

#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "player.h"
using namespace std;

class topten
{
public:
	topten();
	topten(const topten &);
	void geths();
	bool checkscore(player &p);
	void savescores();
	string tostring(int n);
private:
	player myp[10];
};

topten::topten()
{
	for (int i = 0;i < 10;i++) {
		myp[i].setn("");
		myp[i].sets(0);
	}
}
topten::topten(const topten & obj)
{

}
void topten::geths()
{

	string line;
	string sscore;
	int i = 1;
	int n = 0;
	ifstream myfile("topten.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (i % 2 != 0) {
				myp[n].setn(line);
			}
			else {
				sscore = line;
				int score;
				istringstream buffer(sscore);
				buffer >> score;
				myp[n].sets(score);
				n++;
			}
			i++;
		}
		myfile.close();
	}
}
bool topten::checkscore(player &p)
{
	bool nhscore = false;
	if (p.gets() > myp[9].gets()) {
		myp[9] = p;
		nhscore = true;
		player temp;
		for (int i = 0; i < 9; i++){
			for (int j = (i + 1); j < 10; j++){
				if (myp[i].gets() < myp[j].gets()){
					temp = myp[i];
					myp[i] = myp[j];
					myp[j] = temp;
				}
			}
		}
	}
	return nhscore;
}
void topten::savescores()
{
	ofstream myfile("topten.txt");
	if (myfile.is_open())
	{
		int i = 0;
		while (i <= 9) {
			myfile << myp[i].getn() << endl;
			myfile << myp[i].gets() << endl;
			i++;
		}
		myfile.close();
	}
}
string topten::tostring(int n)
{
	string output;
	ostringstream b1;
	b1 << myp[n].gets();
	output = myp[n].getn() + '\t' + b1.str();
	return output;
}
#endif