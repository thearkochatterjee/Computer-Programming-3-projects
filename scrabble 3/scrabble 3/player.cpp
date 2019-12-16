#include "stdafx.h"
#include "player.h"

player::player()
{
	nump = 0;
}
player::player(string name, double score)
{
	nump = nump;
}
player::~player()
{

}
void player::setplayername(vector<std::string> pname)
{
	for (int i = 1; i <= nump; i++)
	{
		name[i] = pname[i];
	}
}
void player::setplayerscore(double pscore[100], int num)
{
	nump = num;
	for (int i = 1; i <= nump; i++)
	{
		ps[i] = pscore[i];
	}
}
void player::addplayer(string pname, double score)
{
	nump++;
	ps[nump] = score;
	name[nump] = pname;
}
void player::sort()
{
	string tempn;
	double temps;
	for (int f = 1; f < nump; f++)
	{
		for (int b = f; b <= nump; b++)
		{
			if (ps[f] > ps[b])
			{
				temps = ps[f];
				tempn = name[f];
				ps[f] = ps[b];
				name[f] = name[b];
				ps[b] = temps;
				name[b] = tempn;
			}
		}
	}
}
void player::createt(int nts[], string nlet[])
{
	for (int i = 1; i <= 98; i++)
	{
		let[i] = nlet[i];
		score[i] = nts[i];
	}
	for (int i = 1; i <= 2; i++)
	{
		let[i + 98] = " ";
		score[i + 98] = 0;
	}
}
void player::shuffle()
{
	int rnum;
	string tlet;
	int tscore;
	for (int i = 1; i <= 100; i++)
	{
		rnum = (int)(rand() % 100 + 1);
		tlet = let[i];
		let[i] = let[rnum];
		let[rnum] = tlet;
		tscore = score[i];
		score[i] = score[rnum];
		score[rnum] = tscore;
	}
}
void player::openw(vector<std::string> words)
{
	for (int i = 1; i <= 58113; i++)
	{
		w[i] = words[i];
	}
}
int player::checkw(string mw)
{
	long pos;
	long low;
	long high;
	long md;
	pos = 0;
	low = 1;
	high = 58113;
	do
	{
		md = (int)((low + high) / 2);
		if (mw > w[md])
		{
			low = md + 1;
		}
		else if (mw<w[md])
		{
			high = md - 1;
		}
		else
		{
			pos = md;
			break;
		}
	} while (low <= high);
	if (pos <= 0)
	{
		pos = 1;
	}
	else
	{
		pos = 0;
	}
	return pos;
}
void player::replace(int p)
{
	if (p == 10)
	{

	}
	else if ((p > 0) && (p < 8))
	{

	}
}
double player::tps(string mw)
{
	int pos;
	double s;
	s = 0;
	for (int x = 1; x <= mw.length(); x++)
	{
		for (int y = 1; y <= 100; y++)
		{
			if (mw.substr(x, 1) == let[y])
			{
				pos = y;
			}
		}
		s = s + score[pos];
	}
	return s;
}
int player::getnump()
{
	return nump;
}
string player::tostringn()
{
	string output;
	ostringstream b;
	output = "";
	for (int i = 1; i <= nump; i++)
	{
		b << name[i] << endl;
		output = b.str();
	}
	return output;
}
string player::tostrings()
{
	string output;
	ostringstream b;
	output = "";
	for (int i = 1; i <= nump; i++)
	{
		b << score[i] << endl;
		output = b.str();
	}
	return output;
}