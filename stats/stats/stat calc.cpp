#include "stdafx.h"
#include "stat calc.h"
void stat::setnums()
{
	mynon = 0;
	mymin = 0;
	mymax = 0;
}
void stat::setnums(int non, double min, double max)
{
	mynon = non;
	mymin = min;
	mymax = max;
	rge = max - min;
}
void stat::genarrnum()
{
	for (int i = 1; i <= mynon; i++)
	{
		arrnum[i] = (int)(rand() % rge + mymin);
	}
}
double stat::getrange()
{
	ans = rge;
	return ans;
}
double stat::mode()
{
	int numnum[100];
	int temp;
	int f;
	for (int i = 1; i <= mynon; i++)
	{
		f = arrnum[i];
		numnum[f]++;
	}
	for (int x = 1; x <= mynon - 1; x++)
	{
		for (int y = x + 1; y <= mynon; y++)
		{
			if (numnum[x] > numnum[y])
			{
				temp = numnum[x];
				numnum[x] = numnum[y];
				numnum[y] = temp;
			}
		}
	}
	ans = numnum[1];
	return ans;
}
double stat::mean()
{
	ans = 0;
	for (int i = 1; i <= mynon; i++)
	{
		ans = ans + arrnum[i];
	}
	ans = ans / mynon;
	return ans;
}
double stat::median()
{
	int temp;
	for (int x = 1; x <= mynon - 1; x++)
	{
		for (int y = x + 1; y <= mynon; y++)
		{
			if (arrnum[x] > arrnum[y])
			{
				temp = arrnum[x];
				arrnum[x] = arrnum[y];
				arrnum[y] = temp;
			}
		}
	}
	return ans;
}
void stat::funum()
{
	for (int i = 1; i <= mynon; i++)
	{

	}
}
void stat::shuffle()
{
	int rpos;
	int temp;
	for (int i = 1; i <= mynon; i++)
	{
		rpos = (int)(rand() % rge + mymin);
		temp = arrnum[i];
		arrnum[i] = arrnum[rpos];
		arrnum[rpos] = temp;
	}
}
string stat::tostring()
{
	string output;
	ostringstream b1;
	b1 << ans;
	output = "The answer is " + b1.str() +" \n";
	return output;
}