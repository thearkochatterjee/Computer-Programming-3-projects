#include "player.h"

player::player()
{
	nump = 0;
}
player::~player()
{

}
void player::setplayername(std::vector<std::string> pname, int i)
{
	nump = i;
	for (int x = 1; x <= nump; x++)
	{
		names[x] = pname[x];
	}
}
void player::setplayerscore(double pscore[])
{
	for (int i = 1; i <= nump; i++)
	{
		scores[i] = pscore[i];
	}
}
void player::addplayer(string name, double score)
{
	nump++;

}
void player::sort()
{
	/*for (int f = 1; f < nump; f++)
	{
		for (int b = f; b <= nump; b++)
		{
			if (arrp[f].score > arrp[b].score)
			{
				temp = arrp[f];
				arrp[f] = arrp[b];
				arrp[b] = temp;
			}
		}
	}*/
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
	int found;
	found = 0;
	for (int i = 1; i <= 58113; i++)
	{
		if (mw == w[i])
		{
			found = 1;
			break;
		}
	}
	return found;
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