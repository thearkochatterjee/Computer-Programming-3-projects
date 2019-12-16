#include <SFML/Graphics.hpp>
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
void input(player arrp[], vector<std::string> words, player bot);
void openpscore(vector<std::string> pname);
void openpname();
void opent(vector<std::string> words);
void openw();

//void kisgod()
//{
//	// varible declaration
//	string line; // word input
//	ifstream myfile("kisgod.txt"); // path
//	if (myfile.is_open())
//	{
//		while (getline(myfile, line))
//		{
//			cout << line << endl;
//		}
//		myfile.close();
//	}
//	else cout << "Unable to open file\n";
//}
//void saves(int nump)
//{
//	player arrp[1000];
//	ofstream myfile("pscore.txt");
//	if (myfile.is_open())
//	{
//		for (int i = 1; i <= nump; i++)
//		{
//			myfile << arrp[i].pscore << endl;
//		}
//		myfile.close();
//	}
//	else cout << "Unable to open file";
//	saven(nump);
//}
//void saven(int nump)
//{
//	player arrp[1000];
//	ofstream myfile("pname.txt");
//	if (myfile.is_open())
//	{
//		for (int i = 1; i <= nump; i++)
//		{
//			myfile << arrp[i].name << endl;
//		}
//		myfile.close();
//	}
//	else cout << "Unable to open file";
//	kisgod();
//}
//void input(vector<std::string> words, int nump)
//{
//	string mw;
//	int p;
//	char op;
//	int e;
//	player bot;
//	player arrp[1000];
//	cout << "Press h for help\n";
//	bot.openw(words);
//	cout << "If you want to clear the word press 0\n";
//	cout << "Enter 10 to submit word\n";
//	cout << "Enter 11 to replace placed letter\n";
//	cout << "Enter 12 to give up\n";
//	bot.shuffle();
//	do
//	{
//		bot.alet();
//		cin >> p;
//		if (p == 0)
//		{
//			mw = "";
//		}
//		else if (p == 10)
//		{
//			if (bot.checkw(mw) == 1)
//			{
//				bot.replace(p);
//				arrp[nump].tps(mw);
//			}
//			else
//			{
//				cout << "Not a word\n";
//			}
//		}
//		else if (p == 11)
//		{
//
//		}
//		else if (p == 12)
//		{
//			cout << "Are you sure you want to give up?\n";
//			cin >> op;
//			if (op == 'y')
//			{
//				break;
//				
//			}
//		}
//		else if ((p > 0) && (p < 8))
//		{
//			mw = mw + bot.avlet[p];
//			bot.replace(p);
//		}
//		else
//		{
//			cout << "Invalid operation\n";
//		}
//	} while (e == 0);
//}
void openpscore()
{
	// varible declaration
	player bot;
	string line; // word input
	ifstream myfile("pscore.txt"); // path
	int nump;
	double pscore[100]; // array for holding the words
	if (myfile.is_open())
	{
		nump = 0;
		while (getline(myfile, line))
		{
			nump++;
			istringstream buffer(line);
			buffer >> pscore[nump];
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	bot.setplayerscore(pscore);
}
void openpname(string name)
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
		pname.resize(100);
		while (getline(myfile, line))
		{
			i++;
			pname[i] = line;
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	bot.setplayername(pname, i);
}
void opent()
{
	// varible declaration
	int num[100];
	int ts[100];
	string let[100];
	string nlet[100];
	int nts[100];
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
			istringstream buffer2(cstring);
			buffer2 >> num[x];
		}
		else
		{
			cstring = tiles[x].substr(3, 2);
			istringstream buffer3(cstring);
			buffer3 >> ts[x];
			cstring = tiles[x].substr(5, tiles[x].length() - 4);
			istringstream buffer4(cstring);
			buffer4 >> num[x];
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
}
void openw()
{
	// varible declaration
	player bot;
	string line; // word input
	ifstream myfile("dictionary.txt"); // path
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
}
int main()
{
	int bpos;
	int rb;
	int rpos;
	string name;
	cout << "What is your name?\n";
	cin >> name;
	//openw();
	//opent();
	//openpname(name);
	//openpscore();
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Scrabble");
	sf::RectangleShape lb[8];
	sf::Text lt[8];
	sf::RectangleShape ab[8];
	sf::Text at[8];
	sf::RectangleShape sub;
	sf::Text subt;
	sf::RectangleShape score;
	sf::Text scoret;
	sf::RectangleShape quit;
	sf::Text quitt;
	sf::RectangleShape nl;
	sf::Text nlt;
	sf::Text e1;
	sf::Text e2;
	sf::Text e3;
	sf::Text e4;
	sf::Font font;
	
	font.loadFromFile("castelar.ttf");
	rb = (int)(rand() % 4 + 1);
	rpos = (int)(rand() % 7 + 1);
	bpos = 10;
	for (int i = 1; i <= 7; i++)
	{
		lb[i].setSize(sf::Vector2f(100, 50));
		lb[i].setOutlineColor(sf::Color::Red);
		lb[i].setOutlineThickness(5);
		lb[i].setPosition(bpos, 500);
		lt[i].setFont(font);
		lt[i].setString("A");
		lt[i].setCharacterSize(24);
		lt[i].setColor(sf::Color::Cyan);
		lt[i].setPosition(bpos + 20, 500);
		ab[i].setSize(sf::Vector2f(100, 50));
		if (i == rpos)
		{
			if (rb == 1)
			{
				ab[i].setOutlineColor(sf::Color::Yellow);
			}
			else if (rb == 2)
			{
				ab[i].setOutlineColor(sf::Color::Blue);
			}
			else if (rb == 3)
			{
				ab[i].setOutlineColor(sf::Color::Green);
			}
			else if (rb == 4)
			{
				ab[i].setOutlineColor(sf::Color::Magenta);
			}
		}
		else
		{
			ab[i].setOutlineColor(sf::Color::Red);
		}
		ab[i].setOutlineThickness(5);
		ab[i].setPosition(bpos, 20);
		at[i].setString("A");
		at[i].setFont(font);
		at[i].setCharacterSize(24);
		at[i].setColor(sf::Color::Cyan);
		at[i].setPosition(bpos + 20, 20);
		bpos = bpos + 120;
	}
	sub.setSize(sf::Vector2f(100, 50));
	sub.setOutlineColor(sf::Color::Red);
	sub.setOutlineThickness(5);
	sub.setPosition(1000, 20);
	subt.setString("Submit");
	subt.setCharacterSize(24);
	subt.setColor(sf::Color::Cyan);
	subt.setPosition(1020, 20);
	score.setSize(sf::Vector2f(100, 50));
	score.setOutlineColor(sf::Color::Red);
	score.setOutlineThickness(5);
	score.setPosition(1000, 90);
	scoret.setString("Score");
	scoret.setCharacterSize(24);
	scoret.setColor(sf::Color::Cyan);
	scoret.setPosition(1020, 90);
	quit.setSize(sf::Vector2f(100, 50));
	quit.setOutlineColor(sf::Color::Red);
	quit.setOutlineThickness(5);
	quit.setPosition(1000, 160);
	quitt.setString("Quit");
	quitt.setCharacterSize(24);
	quitt.setColor(sf::Color::Cyan);
	quitt.setPosition(1020, 160);
	nl.setSize(sf::Vector2f(100, 50));
	nl.setOutlineColor(sf::Color::Red);
	nl.setOutlineThickness(5);
	nl.setPosition(1000, 230);
	nlt.setString("New Letter");
	nlt.setCharacterSize(24);
	nlt.setColor(sf::Color::Cyan);
	nlt.setPosition(1020, 230);
	e1.setString("Yellow - Double Word Score");
	e1.setCharacterSize(50);
	e1.setColor(sf::Color::Yellow);
	e1.setPosition(1000, 300);
	e2.setString("Blue - Triple Word Score");
	e2.setCharacterSize(50);
	e2.setColor(sf::Color::Blue);
	e2.setPosition(1000, 350);
	e3.setString("Green - Double Letter Score");
	e3.setCharacterSize(50);
	e3.setColor(sf::Color::Green);
	e3.setPosition(1000, 400);
	e4.setString("Magenta - Triple Word Score");
	e4.setCharacterSize(50);
	e4.setColor(sf::Color::Magenta);
	e4.setPosition(1000, 450);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 1; i <= 7; i++)
		{
			window.draw(lb[i]);
			window.draw(lt[i]);
			window.draw(ab[i]);
			window.draw(at[i]);
		}
		window.draw(sub);
		window.draw(subt);
		window.draw(score);
		window.draw(scoret);
		window.draw(quit);
		window.draw(quitt);
		window.draw(nl);
		window.draw(nlt);
		window.draw(e1);
		window.draw(e2);
		window.draw(e3);
		window.draw(e4);
		window.display();
	}
	return 0;
}
