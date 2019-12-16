#ifndef _HAND_H
#define _HAND_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include "tile.h"
using namespace std;

class hand
{
public:
	hand();
	hand(const hand &);
	tile gett(int t);
	void sett(int &n, tile &t);
private:
	tile myt[7];
};

hand::hand()
{
	for (int i = 0;i < 7;i++) {
		myt[i].getl() = "";
	}
}

hand::hand(const hand & h)
{
	for (int i = 0;i < 7;i++) {
		myt[i] = h.myt[i];
	}
}

tile hand::gett(int t)
{
	return myt[t];
}

void hand::sett(int &n, tile &t)
{
	myt[n] = t;
}
#endif