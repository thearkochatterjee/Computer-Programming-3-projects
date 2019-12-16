#ifndef _SCRABBLE_H
#define _SCRABBLE_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include "bagoftiles.h"
#include "randgen.h"
#include "player.h"
using namespace std;

class scrabble
{
public:
	void getwords();
	void grabtiles(player &p, bagoftiles &b);
	void replace(player &p, bagoftiles &b, int &n);
	void scoreword(player &p, bagoftiles &b, string &w);
	int checkhand(player &p, string &w);
	int checkword(string &w);
private:
	string *myw = new string[80000];
	int mynw;
};

void scrabble::getwords()
{
	string line;
	ifstream myfile("words.txt");
	int i = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			myw[i] = line;
			i++;
		}
		myfile.close();
	}
	mynw = i;
}

void scrabble::grabtiles(player &p, bagoftiles &b)
{
	RandGen r;
	hand h;
	for (int i = 0;i < 7;i++) {
		h.sett(i, b.gett(r.RandInt(100)));
	}
	p.seth(h);
}

void scrabble::replace(player &p, bagoftiles &b, int &n)
{
	tile blank("", 0);
	RandGen r;
	hand h;
	h = p.geth();
	int i = 0;
	while(i < 7) {
		if (p.geth().gett(i).getl() == "") {
			int j = r.RandInt(100);
			if (b.gett(j).getl() != "") {
				h.sett(i, b.gett(j));
				b.sett(j, blank);
				i++;
			}	
		}
		else {
			i++;
		}
	}
	p.seth(h);
}

void scrabble::scoreword(player &p, bagoftiles &b, string &w)
{
	tile blank("", 0);
	hand h(p.geth());
	for (int i = 0;i <= w.length();i++) {
		stringstream ss;
		string let;
		ss << w[i];
		ss >> let;
		for (int j = 0;j < 7;j++) {
			string leth = p.geth().gett(j).getl();
			if (let == leth) {
				p.sets(p.gets() + p.geth().gett(j).getv());
				h.sett(j, blank);
				p.seth(h);
				break;
			}
		}
	}
}

int scrabble::checkhand(player &p, string &w)
{
	int check = 1;
	int flag = 0;
	for (int i = 0;i < w.length();i++) {
		stringstream ss;
		string let;
		ss << w[i];
		ss >> let;
		for (int j = 0;j < 7;j++) {
			string hlet = p.geth().gett(j).getl();
			if (let == hlet) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			check = 0;
			break;
		}
		flag = 0;
	}
	return check;
}

int scrabble::checkword(string &w)
{
	int exist = 0;
	for (int i = 0;i < mynw;i++) {
		if (w == myw[i]) {
			exist = 1;
			break;
		}
	}
	return exist;
}
#endif