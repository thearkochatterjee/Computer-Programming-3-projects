// roman number converter
// Programmer: Arko Chatterjee
//
// Purpose: convert numbers from arabic to roman and roman to arabic

#include "stdafx.h"
#include <string.h>
#include <sstream>
#include <Windows.h>
#include <iostream>
using namespace std; // needed for using cin and cout

int _tmain(int argc, _TCHAR* argv[])
{
	//varible declaration
	char ans; // used for looping program
	int cncho; // users choice of how to convert data
	char rnum[101]; // roman numberal
	int i; // counter
	int x; // counter
	long num; // resulting arabic number
	long lo; // left over value 1
	long lo2; // left over value 2
	long numm; // number of Ms to add to roman number array
	long numd; // number of Ds to add to roman number array
	long numc; // number of Cs to add to roman number array
	long numl; // number of Ls to add to roman number array
	long numx; // number of Xs to add to roman number array
	long numv; // number of Vs to add to roman number array
	long numi; // number of Is to add to roman number array
	int fnumi;
	int fnumx;
	int fnumc;
	int fnumv;
	int fnuml;
	int fnumd;
	int fnumm;
	system("color 03");

	do
	{
		// asks user for input
		cout << "How do you want to convert the data?\n";
		cout << "Press 1 for converting from arabic to roman\n";
		cout << "Press 2 for converting from roman to arabic\n";
		cin >> cncho;

		// converts data
		cout << "What is the value you want to convert?\n";
		i = 0;
		// arabic to roman
		if (cncho == 1)
		{
			// ask user for input
			cin >> num;
			cout << endl;

			// converting value
			fnumc = 0;
			fnumd = 0;
			fnumi = 0;
			fnuml = 0;
			fnumm = 0;
			fnumv = 0;
			fnumx = 0;
			numm = 0;
			numd = 0;
			numc = 0;
			numl = 0;
			numx = 0;
			numv = 0;
			numi = 0;
			lo = num % 1000;
			numm = (num - lo) / 1000;
			lo2 = lo % 500;
			numd = (lo - lo2) / 500;
			lo = lo2 % 100;
			numc = (lo2 - lo) / 100;
			lo2 = lo % 50;
			numl = (lo - lo2) / 50;
			lo = lo2 % 10;
			numx = (lo2 - lo) / 10;
			lo2 = lo % 5;
			numv = (lo - lo2) / 5;
			lo = lo2 % 1;
			numi = (lo2 - lo) / 1;

			//output data
			cout << "The roman numeral for this number is ";
			i = 0;
			if (numm != 0)
			{
				do
				{
					cout << "M";
					if (i == (numm-1))
					{
						if ((numd == 1) && (numc == 4))
						{
							cout << "CM";
							numd = 0;
							numc = 0;
						}
					}
					i++;
				} while ((i < numm));
			}
			i = 0;
			if ((numd != 0) || (numc == 4))
			{
				if (numc == 4)
				{
					cout << "CD";
					numc = 0;
				}
				else
				{
					cout << "D";
				}
			}
			i = 0;
			if ((numl == 1) && (numx == 4) || (numc != 0))
			{
				do
				{
					if (numc != 0)
					{
						cout << "C";
					}
					if (i == (numc-1)||(numc==0))
					{
						if ((numl == 1) && (numx == 4))
						{
							cout << "XC";
							numl = 0;
							numx = 0;
						}
					}
					i++;
				} while (i < numc);
			}
			i = 0;
			if ((numl != 0)||(numx==4))
			{
				if (numx == 4)
				{
					cout << "XL";
					numx = 0;
				}
				else
				{
					cout << "L";
				}
			}
			i = 0;
			if ((numx != 0) || (numi==4)&&(numv==1))
			{
				do
				{
					if (numx != 0)
					{
						cout << "X";
					}
					if ((i == (numx - 1))||(numx==0))
					{
						if ((numv == 1) && (numi == 4))
						{
							cout << "IX";
							numv = 0;
							numi = 0;
						}
					}
					i++;
				} while (i < numx);
			}
			i = 0;
			if ((numv != 0) || (numi==4))
			{
				if (numi == 4)
				{
					cout << "IV";
					numi = 0;
				}
				else
				{
					cout << "V";
				}
			}
			i = 0;
			if (numi != 0)
			{
				do
				{
					cout << "I";
					i++;
				} while (i < numi);
			}
			cout << endl;
			cout << endl;
		}

		// roman to arabic
		if (cncho == 2)
		{
			fnumc = 0;
			fnumd = 0;
			fnumi = 0;
			fnuml = 0;
			fnumv = 0;
			fnumx = 0;
			fnumm = 0;
			i = 0;
			num = 0;
			cin >> rnum;
			cout << endl;
			do
			{
				if (rnum[i] == 'm')
				{
					num = num + 1000;
				}
				else if (rnum[i] == 'd')
				{
					if (rnum[i + 1] == 'm')
					{
						num = num - 500;
					}
					else
					{
						num = num + 500;
					}
				}
				else if (rnum[i] == 'c')
				{
					if ((rnum[i + 1] == 'm') | (rnum[i + 1] == 'd'))
					{
						num = num - 100;
					}
					else
					{
						num = num + 100;
					}
				}
				else if (rnum[i] == 'l')
				{
					if ((rnum[i + 1] == 'm') | (rnum[i + 1] == 'd') | (rnum[i + 1] == 'c'))
					{
						num = num - 50;
					}
					else
					{
						num = num + 50;
					}
				}
				else if (rnum[i] == 'x')
				{
					if ((rnum[i + 1] == 'm') | (rnum[i + 1] == 'd') | (rnum[i + 1] == 'c') | (rnum[i + 1] == 'l'))
					{
						num = num - 10;
					}
					else
					{
						num = num + 10;
					}
				}
				else if (rnum[i] == 'v')
				{
					if ((rnum[i + 1] == 'm') | (rnum[i + 1] == 'd') | (rnum[i + 1] == 'c') | (rnum[i + 1] == 'l') | (rnum[i + 1] == 'x'))
					{
						num = num - 5;
					}
					else
					{
						num = num + 5;
					}
				}
				else if (rnum[i] == 'i')
				{
					if ((rnum[i + 1] == 'm') | (rnum[i + 1] == 'd') | (rnum[i + 1] == 'c') | (rnum[i + 1] == 'l') | (rnum[i + 1] == 'x') | (rnum[i + 1] == 'v'))
					{
						num--;
					}
					else
					{
						num++;
					}
				}
				else
				{
					i = 99;
				}
				i++;
			} while (i != 100);

			// output data
			cout << "The arabic number for this value is " << num << endl;
			cout << endl;
		}

		// ask user if they want to run again
		cout << "Do you wan to run program again?\n";
		cout << "y for yes, n for no\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

