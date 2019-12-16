// scrabble 2
// programmer: arko chatterjee
//
// purpose: play scrabble

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "player.h"
using namespace std;


void egame();
void input(player p, vector<std::string> words, player bot);
void openpscore(vector<std::string> pname);
void openpname();
void opent(vector<std::string> words);
void openw(int nump);

void tten()
{
	for (int i = 1; i <= 10; i++)
	{

	}
}
void kisgod()
{
	// varible declaration
	string line; // word input
	ifstream myfile("kisgod.txt"); // path
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
}
void saves()
{
	player bot;
	ofstream myfile("pscore.txt");
	int nump;
	nump = bot.getnump();
	if (myfile.is_open())
	{
		for (int i = 1; i <= nump; i++)
		{
			myfile << bot.tostrings << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
void saven()
{
	player bot;
	ofstream myfile("pname.txt");
	int nump;
	nump = bot.getnump();
	if (myfile.is_open())
	{
		for (int i = 1; i <= nump; i++)
		{
			myfile << bot.tostringn << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
void egame(double score)
{
	char ans;
	player bot;
	string pname;
	cout << "What is your name?\n";
	cin >> pname;
	bot.addplayer(pname, score);
	cout << "Would you like to see the Top Ten?\n";
	cin >> ans;
	if (ans == 'y')
	{
		tten();
	}
	saves();
	saven();
	kisgod();
}
void input()
{
	string mw;
	int p;
	int pos;
	char op;
	int e;
	double score;
	int rpos;
	player bot;
	cout << "Press h for help\n";

	cout << "If you want to clear the word press 0\n";
	cout << "Enter 10 to submit word\n";
	cout << "Enter 11 to replace placed letter\n";
	cout << "Enter 12 to give up\n";
	bot.shuffle();
	do
	{
		bot.alet();
		cin >> p;
		if (p == 0)
		{
			mw = "";
		}
		else if (p == 10)
		{
			if (bot.checkw(mw) == 1)
			{
				bot.replace(p);

			}
			else
			{
				cout << "Not a word\n";
			}
		}
		else if (p == 11)
		{
			cout << "What is the position of the letter you want to replace?\n";
			cin >> rpos;
			cout << "What is the position of the letter you want to replace it with?\n";
			cin >> pos;

		}
		else if (p == 12)
		{
			cout << "Are you sure you want to give up?\n";
			cin >> op;
			if (op == 'y')
			{
				egame(score);
				break;
			}
		}
		else if ((p > 0) && (p < 8))
		{
			mw = mw + bot.avlet[p];
			bot.replace(p);
		}
		else
		{
			cout << "Invalid operation\n";
		}
	} while (e == 0);
}
void opent()
{
	// varible declaration
	int num[26];
	int ts[26];
	string let[26];
	string nlet[98];
	int nts[98];
	string cstring;
	player bot;
	int pos;
	int pos2;
	string line; // word input
	ifstream myfile("scrabblevalues.txt"); // path
	long i; // counter
	int a;
	std::vector<std::string> tiles; // array for holding the words
	// opens file
	if (myfile.is_open())
	{
		i = 0;
		tiles.resize(26);
		while (getline(myfile, line))
		{
			i++;
			tiles[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	for (int x = 1; x <= 26; x++)
	{
		let[x] = tiles[x].substr(1, 1);
		if (tiles[x].substr(4, 1) == " ")
		{
			cstring = tiles[x].substr(3, 1);
			istringstream buffer(cstring);
			buffer >> ts[x];
			cstring = tiles[x].substr(4, tiles[x].length() - 3);
			istringstream buffer(cstring);
			buffer >> num[x];
		}
		else
		{
			cstring = tiles[x].substr(3, 2);
			istringstream buffer(cstring);
			buffer >> ts[x];
			cstring = tiles[x].substr(5, tiles[x].length() - 4);
			istringstream buffer(cstring);
			buffer >> num[x];
		}
	}
	a = 0;
	for (int x = 1; x <= 26; x++)
	{
		for (int y = 1; y <= num[x]; y++)
		{
			a++;
			nlet[a] = let[x];
			nts[a] = ts[x];
		}
	}
	bot.createt(nts, nlet);
	bot.shuffle();
	input();
}
void openw()
{
	// varible declaration
	string line; // word input
	ifstream myfile("dictionary.txt"); // path
	player bot;
	long i; // counter
	std::vector<std::string> words; // array for holding the words
	// opens file
	if (myfile.is_open())
	{
		i = 0;
		words.resize(58113);
		while (getline(myfile, line))
		{
			i++;
			words[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	bot.openw(words);
	opent();
}
void openpscore()
{
	// varible declaration
	player bot;
	string line; // word input
	ifstream myfile("pscore.txt"); // path
	int num;
	double pscore[100]; // array for holding the words
	if (myfile.is_open())
	{
		num = 0;
		while (getline(myfile, line))
		{
			num++;
			istringstream buffer(line);
			buffer >> pscore[num];
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	bot.setplayerscore(pscore, num);
}
void openpname()
{
	// varible declaration
	player bot;
	string line; // word input
	ifstream myfile("pname.txt"); // path
	long i; // counter
	std::vector<std::string> pname; // array for holding the words
	if (myfile.is_open())
	{
		i = 0;
		pname.resize(1000);
		while (getline(myfile, line))
		{
			i++;
			pname[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	bot.setplayername(pname);
}
int main()
{
	char ans;
	do
	{
		openpscore();
		openpname();
		openw();
		cout << "Do you want to run program again?\n";
		cin >> ans;
	} while (ans == 'y');
}

