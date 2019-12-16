// Scrabble
// Programmer: Arko Chatterjee
//
// Purpose: play scrabble

#include "scrabble.h"
#include "topten.h"
#include <iostream>
#include <string>
using namespace std;

void game(scrabble &s, bagoftiles &b, player &p);
void scores(player &p);

void game(scrabble &s, bagoftiles &b, player &p) {
	string name;
	cout << "What is your name?\n";
	cin >> name;
	p.setn(name);
	int play;
	int nt = 0;
	s.grabtiles(p, b);
	cout << p.handstring() << endl;
	do {
		if (nt == 100) {
			cout << "No more tiles left in the bag." << endl;
		}
		string word;
		cout << "Enter a word no more than 7 letters:\n";
		cin >> word;
		int allowed = s.checkhand(p, word);
		char blet;
		string finword;
		finword = word;
		for (int i = 0;i <= word.length();i++) {
			if (word[i] == '!') {
				cout << "What letter would you like the blank tile to be?\n";
				cin >> blet;
				finword = word;
				finword[i] = blet;
				cout << finword << endl;
			}
		}
		int exists = s.checkword(finword);
		if (allowed == 1 && exists == 1) {
			s.scoreword(p, b, word);
			cout << "Current score: " << p.gets() << endl;
			s.replace(p, b, nt);
			cout << p.handstring() << endl;
			cout << "Do you want to keep playing(1/0)?\n";
			cin >> play;
			if (play == 0) {
				break;
			}
		}
		else {
			cout << "Word does not exist or word needs tiles you do not have." << endl;
		}
	} while (1 == 1);
}
void scores(player &p)
{
	topten t;
	t.geths();
	if (t.checkscore(p) == true) {
		cout << "New High Score" << endl;
		for (int i = 0;i < 10;i++) {
			cout << t.tostring(i) << endl;
		}
	}
	t.savescores();
}
int main()
{
	system("color 30");
	cout << "              Scrabble\n";
	bagoftiles bt;
	bt.gettiles();
	bt.shuffle();
	scrabble sc;
	sc.getwords();
	player p1;
	game(sc, bt, p1);
	scores(p1);
	system("pause");
	return 0;
}