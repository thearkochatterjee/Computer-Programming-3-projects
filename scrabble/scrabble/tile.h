#ifndef _TILE_H
#define _TILE_H

#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class tile 
{
public:
	tile();
	tile(string l, int v);
	string getl();
	int getv();
	void setl(string &l);
	void setv(int &v);
private:
	string myl;
	int myv;
};

tile::tile()
{
	myl = "";
	myv = 0;
}
tile::tile(string l, int v)
{
	myl = l;
	myv = v;
}
string tile::getl()
{
	return myl;
}
int tile::getv()
{
	return myv;
}
void tile::setl(string &l)
{
	myl = l;
}
void tile::setv(int &v)
{
	myv = v;
}
#endif