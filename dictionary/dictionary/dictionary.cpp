// dictionary
// Programmer: Arko Chatterjee
//
// Purpose: show a list of words and find longest word

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; // needed for cin and cout

// funtion prototypes
void openfile();

// fucntions
void openfile()
{
	// varible declaration
	string line; // word input
	string lword; // longest word
	char ch; // decision varible
	int rnum; // random number
	ifstream myfile("F:\apush terms.txt"); // path
	long i; // counter
	std::vector<std::string> storage; // array for holding the words
	// opens file
	if (myfile.is_open())
	{
		i = 0;
		lword = ' ';
		storage.resize(58113);
		while (getline(myfile, line))
		{
			i++;
			if (line.length() > lword.length())
			{
				lword = line;
			}
			storage[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	// output
	cout << "Dictionary:\n";
	cout << "The longest word is " << lword << endl;
	cout << "The length of the word is " << lword.length() << " long" << endl;
	// shows the list of words
	cout << "Do you want to see all the words in the dictionary?\n";
	cin >> ch;
	if (ch == 'y')
	{
		for (int i = 0; i <= 58112; i++)
		{
			cout << storage[i] << endl;
		}
	}
	// shows random word
	cout << "Do you want a random word?\n";
	cin >> ch;
	if (ch == 'y')
	{
		rnum = (int)(rand() % 58112 + 1);
		cout << "The random word is " << storage[rnum] << endl;
	}
}
int main()
{
	// varible decalration
	char ans;
	// change color
	system("color 03");
	// loop
	do
	{
		// function
		openfile();
		// run program again
		cout << "Do you want to run program again(y/n)?\n";
		cin >> ans;
		system("cls");
	} while (ans == 'y');
	return 0;
}

