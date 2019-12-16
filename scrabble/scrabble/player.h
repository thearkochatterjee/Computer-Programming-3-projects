#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include "hand.h"
using namespace std;

class player
{
public:
	player();
	player(string n, int s, hand h);

	string getn();
	int gets();
	hand geth();
	void setn(string n);
	void sets(int s);
	void seth(hand h);
	string handstring();
private:
	string myn;
	int mys;
	hand myh;
};

player::player()
{
	for (int i = 0;i < 7;i++) {
		myh.gett(i).getl() = "";
	}
	myn = "";
	mys = 0;
}

player::player(string n, int s, hand h)
{
	myn = n;
	mys = s;
	myh = h;
}

string player::getn()
{
	return myn;
}

int player::gets()
{
	return mys;
}

hand player::geth()
{
	return myh;
}

void player::setn(string n)
{
	myn = n;
}

void player::sets(int s)
{
	mys = s;
}

void player::seth(hand h)
{
	myh = h;
}

string player::handstring()
{
	string output;
	for (int i = 0;i < 7;i++) {
		output = output + myh.gett(i).getl() + " ";
	}
	return output;
}
#endif