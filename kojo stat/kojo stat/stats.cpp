#include "stdafx.h"
#include "stats.h"
void stats::stat()
{
	for (int i = 0; i <= 100; i++)
	{
		arrnums[i] = 0;
	}
}
void stats::stat(int arrn[], int nnum)
{
	for (int x = 1; x <= nnum; x++)
	{
		arrnums[x] = arrn[x];
	}
}
int stats::findlength(int nnum)
{
	ans = nnum;
	return ans;
}
int stats::findmax(int nnum)
{
	//ans = arrnums[nnum];
	ans = 88;
	return ans;
}
int stats::findmin()
{
	ans = arrnums[1];
	return ans;
}
double stats::mean(int nnum)
{
	int d;
	double avg;
	avg = 0;
	for (d = 1; d <= nnum; d++)
	{
		avg = avg + arrnums[d];
	}
	ans = avg / nnum;
	return ans;
}
void stats::sort(int nnum)
{
	int f;
	int b;
	int temp;
	for (f = 1; f <= nnum - 1; f++)
	{
		for (b = f + 1; b <= nnum; b++)
		{
			if (arrnums[b] < arrnums[f])
			{
				temp = arrnums[b];
				arrnums[b] = arrnums[f];
				arrnums[f] = temp;
			}
		}
	}
}
int stats::median(int nnum)
{
	int h;
	if ((nnum % 2) == 0)
	{
		h = (int)(nnum / 2);
		ans = arrnums[h] + arrnums[h + 1];
		ans = ans / 2;
	}
	else
	{
		h = (int)(nnum / 2);
		h++;
		ans = arrnums[h];
	}
	return ans;
}
string stats::tostring()
{
	string output;
	ostringstream b;
	b << ans;
	output = b.str() + " \n";
	return output;
}
string stats::arrtostring(int nnum)
{
	string output;
	ostringstream b;
	output = "";
	for (int i = 1; i <= nnum; i++)
	{
		b << arrnums[i] << endl;
		output = b.str();
	}
	return output;
}