#include "dshape.h"

void dshape::setpoints(double x[], double y[])
{
	for (int i = 0; i < 4; i++)
	{
		myx[i] = x[i + 1];
		myy[i] = y[i + 1];
	}
}
double dshape::finddis()
{
	double ans;
	for (int i = 0; i <= 3; i++)
	{
		if (i == 3)
		{
			dis[i] = pow((pow(myx[3] - myx[0], 2) + (pow(myy[3] - myy[0], 2))), 0.5);
		}
		else
		{
			dis[i] = pow((pow(myx[i + 1] - myx[i], 2) + (pow(myy[i + 1] - myy[i], 2))), 0.5);
		}
		ans = dis[i];
	}
	return ans;
}
double dshape::findper()
{
	double ans;
	ans = 0;
	for (int i = 0; i <= 3; i++)
	{
		ans = ans + dis[i];
	}
	per = ans;
	return ans;
}
double dshape::findarea()
{
	double ans;
	ans = 0;
	for (int i = 0; i <= 3; i++)
	{
		if (i == 3)
		{
			ans = ans + ((myx[3] * myy[0]) - (myy[3] * myx[0]));
		}
		else
		{
			ans = ans + ((myx[i] * myy[i + 1]) - (myy[i] * myx[i + 1]));
		}
	}
	ans = abs(ans / 2);
	area = ans;
	return ans;
}
double dshape::getarea()
{
	return area;
}
double dshape::getdis()
{
	double ans;
	for (int i = 0; i <= 3; i++)
	{
		ans = dis[i];
	}
	return ans;
}
double dshape::getper()
{
	return per;
}
string dshape::tostring()
{
	string output;
	ostringstream b;
	output = "";
	for (int i = 0; i <= 5; i++)
	{
		if (i == 4)
		{
			b << "Area: " << area << endl;
		}
		else if (i == 5)
		{
			b << "Perimemter: " << per << endl;
		}
		else
		{
			b << "Distance of Line " << i << " : " << dis[i] << endl;
		}
		output = b.str();
	}
	return output;
}