#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#ifndef player_h
#define player_h
class player
{
public:
	// default constructor
	player();

	// overload constructor
	player(string, double);

	// deconstructor
	~player();

	// accessor function
	void setplayername(vector<std::string> pname);
	void setplayerscore(double pscore[100], int num);
	void addplayer(string name, double score);
	double tps(string mw);

	// mutator funtions
	void sort();
	int getnump();
	string tostrings();
	string tostringn();

	// bag of tiles
	void createt(int nts[], string nlet[]);
	void shuffle(); // sc
	void alet();
	void openw(vector<std::string> words);
	int checkw(string mw);
	string avlet[7];
	void replace(int p);
private:
	// member varible
	string name[100]; // player name
	double ps[100]; // player score
	string let[100]; // array of letter of bag of tiles
	int score[100]; // array of score for each letter in bag
	string w[58113]; // array of words
	int nump; // number of players
};
#endif