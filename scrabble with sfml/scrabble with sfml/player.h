#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;

#ifndef player_h
#define player_h
class player
{
public:
	// default constructor
	player();

	// deconstructor
	~player();

	// accessor function
	void setplayername(std::vector<std::string> pname, int i);
	void setplayerscore(double pscore[100]);
	void addplayer(string name, double score);
	double tps(string mw);

	// mutator funtions
	void sort();

	double getnump;
	

	// bag of tiles
	void createt(int nts[], string nlet[]);
	void shuffle();
	void alet();
	void openw(vector<std::string> words);
	int checkw(string mw);
	string avlet[7];
	void replace(int p);
	string tostring;
private:
	// member varible
	double nump;
	string let[100];
	int score[100];
	string w[58113];
	string names[100];
	double scores[100];
};
#endif