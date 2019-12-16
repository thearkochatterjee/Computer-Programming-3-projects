// jotto
// Programmer: Arko Chatterjee
//
// Purpose: play jotto

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std; // needed for cin and cout

// class
class player
{
public:
	int score;
	string name;
}arrp[1000], tten[10], temp;

// function prototypes
void savescore();
void savename();
void sort();
void win();
void ai(vector<string> words, string word);
void gword(string word, vector<string> words);
void checkw(string word, vector<string> words);
void pickword(vector<string> words, int mode);
void nfile(int mode);
void jfile(int mode);
void input();
void getscores();
void getnames();

// functions
int np;
int start;
void savescore()
{
	ofstream myfile("names.txt");
	if (myfile.is_open())
	{
		for (int i = 1; i <= np; i++)
		{
			myfile << arrp[i].name << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
void savename()
{
	ofstream myfile("scores.txt");
	if (myfile.is_open())
	{
		for (int i = 1; i <= np; i++)
		{
			myfile << arrp[i].score << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
void sort()
{
	for (int f = 0; f <= np - 1; f++)
	{
		for (int b = f + 1; b <= np; b++)
		{
			if (arrp[f].score > arrp[b].score)
			{
				temp = arrp[f];
				arrp[f] = arrp[b];
				arrp[b] = temp;
			}
		}
	}
}
void win()
{
	char ch;
	cout << arrp[np].name << " got a score of " << arrp[np].score << endl;
	cout << "Do you want to see the top ten scores?\n";
	cin >> ch;
	if ((ch == 'y')||(ch=='Y'))
	{
		sort();
		cout << "The Top Ten Scores Are:\n";
		for (int i = 1; i <= 10; i++)
		{
			tten[i] = arrp[i];
			cout << tten[i].name << " -- " << tten[i].score << endl;
		}
	}
	savename();
	savescore();
}
void ai(vector<string> words, string word)
{
	string gword;
	int rnum;
	int tries;
	tries = 0;
	do
	{
		tries++;
		rnum = (int)(rand() % 3038 + 1);
		gword = words[rnum];
	} while (gword != word);
	cout << "It took " << tries << " tries.\n";
	cout << "The word is " << gword << endl;
}
void gword(string rword, vector<string> words)
{
	char let[6];
	char letgsf[27];
	int numlc;
	int numc;
	string gword;
	int n;
	int tries;
	int cont;
	n = 0;
	tries = 0;
	numlc = 0;
	do
	{
		tries++;
		cout << "The word is " << rword << endl;
		cout << endl;
		cout << "What do you think the word is?\n";
		cin >> gword;
		int found;
		found = 0;
		for (int i = 0; i <= 3038; i++)
		{
			if (gword == words[i])
			{
				found = 1;
			}
		}
		if (found == 0)
		{
			cout << "This is not found.\n";
		}
		char *c = const_cast<char*>(gword.c_str());
		char *r = const_cast<char*>(rword.c_str());
		numlc = 0;
		for (int i = 0; i < 5; i++)
		{
			cont = 1;
			for (int x = 0; x < 5; x++)
			{
				if ((c[i] == r[x])&&(cont==1))
				{
					numlc++;
					cont = 0;
				}
			}
		}
		cout << "The number of jots is " << numlc << endl;
		if (gword == rword)
		{
			cout << endl;
			cout << "Congradulations you got the correct word!\n";
			cout << endl;
			arrp[np].score = tries;
			win();
		}
		else
		{
			cout << endl;
			cout << "Word is not correct.\n";
			cout << endl;
		}
	} while (gword != rword);
}
void checkw(string word, vector<string> words)
{
	int found;
	found = 0;
	do
	{
		for (int i = 0; i <= 3038; i++)
		{
			if (word == words[i])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			cout << "Word not found\n";
			cout << "Choose another 5 letter word\n";
			cin >> word;
		}
	} while (found == 0);
	ai(words, word);
}
void pickword(vector<string> words, int mode, int mode2)
{
	int rnum;
	string rword;
	string word;
	if (mode == 1)
	{
		srand(time(NULL));
		if (mode2 == 1)
		{
			rnum = (int)(rand() % 3038 + 1);
		}
		else
		{
			rnum = (int)(rand() % 900 + 1);
		}
		rword = words[rnum];
		gword(rword, words);
	}
	else if (mode == 2)
	{
		cout << "What 5 letter word would you like to use?\n";
		cin >> word;
		checkw(word, words);
	}
}
void nfile(int mode, int mode2)
{
	// varible declaration
	string line;
	ifstream myfile("cname.txt");
	long i;
	vector<string> words(3039);
	string rword;
	string word;
	int rnum;
	if (myfile.is_open())
	{
		i = 0;
		while (getline(myfile, line))
		{
			i++;
			words[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	pickword(words, mode, mode2);
}
void jfile(int mode, int mode2)
{
	// varible declaration
	string line;
	ifstream myfile("jotto.txt");
	long i;
	vector<string> words(3039);
	string rword;
	string word;
	int rnum;
	if (myfile.is_open())
	{
		i = 0;
		while (getline(myfile, line))
		{
			i++;
			words[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	pickword(words, mode, mode2);
}
void input()
{
	int mode;
	int mode2;
	char ch;
	mode = 0;
	if (start == 0)
	{
		np++;
		cout << "Welcome to Jotto\n";
		cout << "What is your name?\n";
		cin >> arrp[np].name;
		arrp[np].score = 0;
		start = 1;
	}
	cout << "Do you want to guess the word made by the computer?\n";
	cin >> ch;
	if (ch == 'y')
	{
		mode = 1;
	}
	else if (ch == 'n')
	{
		mode = 2;
	}
	else
	{
		do
		{
			cout << "Invalid choice\n";
			cout << "Do you want to guess the word?\n";
			cin >> ch;
			if (ch == 'y')
			{
				mode = 1;
			}
			else if (ch == 'n')
			{
				mode = 2;
			}
		} while ((ch != 'y') || (ch != 'n'));
	}
	cout << "Do you want to use the jotto text(j) or names text(n)?\n";
	cin >> ch;
	if (ch == 'j')
	{
		mode2 = 1;
		jfile(mode, mode2);
	}
	else if (ch == 'n')
	{
		cout << "Make sure you capitalize the first letter.\n";
		mode2 = 2;
		nfile(mode, mode2);
	}
}
void getscores()
{
	// varible declaration
	string line;
	ifstream myfile("scores.txt");
	int rnum;
	if (myfile.is_open())
	{
		np = 0;
		while (getline(myfile, line))
		{
			if (line != "0")
			{
				np++;
				istringstream buffer(line);
				buffer >> arrp[np].score;
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	sort();
}
void getname()
{
	// varible declaration
	string line;
	ifstream myfile("names.txt");
	int i;
	int rnum;
	if (myfile.is_open())
	{
		i = 0;
		while (getline(myfile, line))
		{
			if (line != "")
			{
				i++;
				arrp[i].name = line;
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
}

int main()
{
	char ans;
	char ch;
	start = 0;
	system("color 30");
	getname();
	getscores();
	do
	{
		input();
		cout << "Do you want to run program again?(y/n)\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

