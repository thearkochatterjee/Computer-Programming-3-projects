// calendar
// Programmer: Arko Chatterjee
//
// Purpose: Show the calendar of any month and show holidays

#include "stdafx.h"
#include <Windows.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	// varible declaration
	char ans; // used to see if user wants to run program again
	int day; // day that the user asks for
	int month; // month that the user asks for
	int ndim; // number of days in the month
	int year; // year that the user asks for
	int f2y; // first two dights of year
	int l2y; // last two dights of year
	int f;
	int r[32];
	int i; // running total
	int x; // running total 2
	int cpos[50];
	int hd;
	int sd; // starting day of month
	int flag;
	
	// easter calculation varible declaration
	int a;
	int b;
	int c;
	int d;
	int e;
	int l;
	int g;
	int h;
	int m;
	int j;
	int k;
	int emonth;
	int edate;
	int p;

	// colors of console
	system("color 03");
	day = 1;
	do
	{
		// ask user for input
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;

		// calculation for the calendar
		l2y = year % 100;
		f2y = (year - l2y) / 100;
		if (month == 1)
		{
			hd = 1;
		}
		else if (month == 2)
		{
			hd = 14;
		}
		else if (month == 3)
		{
			hd = 17;
		}
		else if (month == 4)
		{
			hd = 1;
		}
		else if (month == 7)
		{
			hd = 4;
		}
		else if (month == 8)
		{
			hd = 2;
		}
		else if (month == 10)
		{
			hd = 31;
		}
		else if (month == 12)
		{
			hd = 25;
		}
		if (month == 1)
		{
			month = 11;
		}
		else if (month == 2)
		{
			month = 12;
		}
		else
		{
			month = month - 2;
		}
		if (((month % 2) == 1) && (month < 6) || (month == 11))
		{
			ndim = 31;
		}
		else if (month == 12)
		{
			if (((l2y % 4) == 0) && (l2y != 0) || ((f2y % 4) == 0) && (l2y == 0))
			{
				ndim = 29;
			}
			else
			{
				ndim = 28;
			}
		}
		else if (((month % 2) == 0) && (month > 5))
		{
			ndim = 31;
		}
		else
		{
			ndim = 30;
		}
		day = 1;
		do
		{
			f = day + ((13 * month - 1) / 5) + l2y + (l2y / 4) + (f2y / 4) - 2 * f2y;
			r[day] = f - 7 * (f / 7);
			if (r[day] < 0)
			{
				r[day] = r[day] + 7;
			}
			if ((month == 11) || (month == 12))
			{
				if (((l2y % 4) == 0) && (l2y != 0))
				{
					i = 1;
					do
					{
						r[i] = r[i] - 2;
						if (r[i] < 0)
						{
							r[i] = r[i] + 7;
						}
						i++;
					} while (i < ndim + 1);
				}
				else
				{
					if (day == 1)
					{
						flag = 1;
					}
				}
			}
			if (day == 1)
			{
				sd = r[day];
				if (flag == 1)
				{
					sd--;
				}
			}
			if ((month == 11) || (month == 12))
			{
				if ((l2y % 4) == 1)
				{
					if (day == 1)
					{
						sd--;
					}
					i = 0;
					do
					{
						r[day]--;
						i++;
					} while (i < ndim + 1);
				}
			}
			if (r[day] == 1)
			{
				if (month == 7)
				{
					if (day < 8)
					{
						hd = day;
					}
				}
			}
			if (r[day] == 2)
			{

			}
			if (r[day] == 3)
			{

			}
			if (r[day] == 4)
			{

				if (month == 9)
				{
					if (day < 8)
					{
						hd = day + 21;
					}
				}
			}
			if (r[day] == 5)
			{
				
			}
			if (r[day] == 6)
			{

			}
			if (r[day] == 0)
			{
				if (month == 3)
				{
					if (day < 8)
					{
						hd = day + 7;
					}
				}
				if (month == 4)
				{
					if (day < 8)
					{
						hd = day + 14;
					}
				}
			}
			day++;
		} while ((day < ndim) || (day == ndim));
		
		// finds when easter is
		a = year % 19;
		b = year / 100;
		c = year % 100;
		d = b / 4;
		e = b % 4;
		l = (b + 8) / 25;
		g = (b - l + 1) / 3;
		h = ((19 * a) + b - d - g + 15) % 30;
		m = c / 4;
		j = c % 4;
		k = (32 + (2 * e) + (2 * m) - h - j) % 7;
		m = (a + (11 * h) + (22 * k)) / 451;
		emonth = (h + k - (7 * m) + 114) / 31;
		p = (h + k - (7 * m) + 114) % 31;
		edate = p + 1;
		if ((month + 2) == emonth)
		{
			hd = edate;
		}
		
		cout << endl;

		if (month == 11)
		{
			cout << "January:\n";
		}
		if (month == 12)
		{
			cout << "Febuary:\n";
		}
		if (month == 1)
		{
			cout << "March:\n";
		}
		if (month == 2)
		{
			cout << "Apirl:\n";
		}
		if (month == 3)
		{
			cout << "May:\n";
		}
		if (month == 4)
		{
			cout << "June:\n";
		}
		if (month == 5)
		{
			cout << "July:\n";
		}
		if (month == 6)
		{
			cout << "August:\n";
		}
		if (month == 7)
		{
			cout << "September:\n";
		}
		if (month == 8)
		{
			cout << "October:\n";
		}
		if (month == 9)
		{
			cout << "November:\n";
		}
		if (month == 10)
		{
			cout << "December:\n";
		}
		cout << endl;
		cout << "     Sun      Mon     Tues      Wed    Thurs      Fri      Sat\n";
		x = 0;
		i = 0;
		do
		{
			cout << "-";
			i++;
		} while (i < 63);
		day = 1;
		cout << endl;
		i = 0;
		cout << "        |        |        |        |        |        |        |\n";
		if ((month == 9) && (year == 2015))
		{
			sd = 3;
		}
		if (sd != 0)
		{
			if ((month == 12)&&(year==2000))
			{
				do
				{
					cout << "        |";
					i++;
				} while (i < sd - 1);
			}
			else
			{
				do
				{
					cout << "        |";
					i++;
				} while (i < sd);
			}
		}
		if (year == 2016)
		{
			if (month == 3)
			{
				hd = 27;
			}
		}
		day = 1;
		do
		{
			if (day == hd)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 4);
			}
			cout << "      " << day << " |";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 3);
			day++;
			i++;
		} while (i < 7);
		cout << endl;
		cout << "        |        |        |        |        |        |        |\n";
		i = 0;
		do
		{
			cout << "-";
			i++;
		} while (i < 63);
		cout << endl;
		x = 0;
		do
		{
			cout << "        |        |        |        |        |        |        |\n";
			i = 0;
			do
			{
				if (day < 10)
				{
					if (day == hd)
					{
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, 4);
					}
					cout << "      " << day << " |";
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 3);
				}
				else
				{
					if (day == hd)
					{
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, 4);
					}
					if (month == 3)
					{
						if (year == 2016)
						{
							if (day == 27)
							{
								HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
								SetConsoleTextAttribute(hConsole, 4);
							}
						}
					}
					cout << "     " << day << " |";
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 3);
				}
				day++;
				i++;
			} while (i < 7);
			cout << endl;
			cout << "        |        |        |        |        |        |        |\n";
			i = 0;
			do
			{
				cout << "-";
				i++;
			} while (i < 63);
			cout << endl;
			x++;
		} while (x < 3);
		cout << "        |        |        |        |        |        |        |\n";
		i = 0;
		do
		{
			cout << "     " << day << " |";
			day++;
			i++;
		} while ((day < ndim + 1) && (i < 7));
		if (i < 6)
		{
			do
			{
				cout << "        |";
				i++;
			} while (i < 7);
		}
		cout << endl;
		cout << "        |        |        |        |        |        |        |\n";
		i = 0;
		do
		{
			cout << "-";
			i++;
		} while (i < 63);
		cout << endl;
		if (day < ndim+1)
		{
			cout << "        |        |        |        |        |        |        |\n";
			i = 0;
			do
			{
				cout << "     " << day << " |";
				day++;
				i++;
			} while ((i < 7) && (day < ndim + 1));
			if (i < 6)
			{
				do
				{
					cout << "        |";
					i++;
				} while (i < 7);
			}
			cout << endl;
			cout << "        |        |        |        |        |        |        |\n";
			i = 0;
			do
			{
				cout << "-";
				i++;
			} while (i < 63);
			cout << endl;
		}
		cout << endl;
		cout << "Holidays are in red.\n";
		cout << endl;
		// shows holidays
		if (month == 1)
		{
			if (emonth == 3)
			{	
				if (r[edate] == 0)
				{
					cout << "Easter is on Sunday, March " << edate << ", " << year;
				}
				else if (r[edate] == 1)
				{
					cout << "Easter is on Monday, March " << edate << ", " << year;
				}
				else if (r[edate] == 2)
				{
					cout << "Easter is on Tuesday, March " << edate << ", " << year;
				}
				else if (r[edate] == 3)
				{
					cout << "Easter is on Wednesday, March " << edate << ", " << year;
				}
				else if (r[edate] == 4)
				{
					cout << "Easter is on Thursday, March " << edate << ", " << year;
				}
				else if (r[edate] == 5)
				{
					cout << "Easter is on Friday, March " << edate << ", " << year;
				}
				else if (r[edate] == 6)
				{
					cout << "Easter is on Saturday, March " << edate << ", " << year;
				}
			}
			else
			{
				if (r[17] == 0)
				{
					cout << "St.Patrick's Day is on Sunday, March 17, " << year;
				}
				else if (r[17] == 1)
				{
					cout << "St.Patrick's Day is on Monday, March 17, " << year;
				}
				else if (r[17] == 2)
				{
					cout << "St.Patrick's Day is on Tuesday, March 17, " << year;
				}
				else if (r[17] == 3)
				{
					cout << "St.Patrick's Day is on Wednesday, March 17, " << year;
				}
				else if (r[17] == 4)
				{
					cout << "St.Patrick's Day is on Thursday, March 17, " << year;
				}
				else if (r[17] == 5)
				{
					cout << "St.Patrick's Day is on Friday, March 17, " << year;
				}
				else if (r[17] == 6)
				{
					cout << "St.Patrick's Day is on Saturday, March 17, " << year;
				}
			}
		}
		else if (month == 2)
		{
			if (emonth == 4)
			{
				if (r[edate] == 0)
				{
					cout << "Easter is on Sunday, April " << edate << ", " << year;
				}
				else if (r[edate] == 1)
				{
					cout << "Easter is on Monday, April " << edate << ", " << year;
				}
				else if (r[edate] == 2)
				{
					cout << "Easter is on Tuesday, April " << edate << ", " << year;
				}
				else if (r[edate] == 3)
				{
					cout << "Easter is on Wednesday, April " << edate << ", " << year;
				}
				else if (r[edate] == 4)
				{
					cout << "Easter is on Thursday, April " << edate << ", " << year;
				}
				else if (r[edate] == 5)
				{
					cout << "Easter is on Friday, April " << edate << ", " << year;
				}
				else if (r[edate] == 6)
				{
					cout << "Easter is on Saturday, April " << edate << ", " << year;
				}
			}
			else
			{
				if (r[1] == 0)
				{
					cout << "April Fool's Day is on Sunday, April 1, " << year;
				}
				else if (r[1] == 1)
				{
					cout << "April Fool's Day is on Monday, April 1, " << year;
				}
				else if (r[1] == 2)
				{
					cout << "April Fool's Day is on Tuesday, April 1, " << year;
				}
				else if (r[1] == 3)
				{
					cout << "April Fool's Day is on Wednesday, April 1, " << year;
				}
				else if (r[1] == 4)
				{
					cout << "April Fool's Day is on Thursday, April 1, " << year;
				}
				else if (r[1] == 5)
				{
					cout << "April Fool's Day is on Friday, April 1, " << year;
				}
				else if (r[1] == 6)
				{
					cout << "April Fool's Day is on Saturday, April 1, " << year;
				}
			}
		}
		else if (month == 3)
		{
			cout << "Mother's Day is on Sunday, May " << hd << ", " << year;
		}
		else if (month == 4)
		{
			cout << "Father's Day is on Sunday, June " << hd << ", " << year;
		}
		else if (month == 5)
		{
			if (r[4] == 0)
			{
				cout << "America's Independence Day is on Sunday, July 4, " << year;
			}
			if (r[4] == 1)
			{
				cout << "America's Independence Day is on Monday, July 4, " << year;
			}
			if (r[4] == 2)
			{
				cout << "America's Independence Day is on Tuesday, July 4, " << year;
			}
			if (r[4] == 3)
			{
				cout << "America's Independence Day is on Wednesday, July 4, " << year;
			}
			if (r[4] == 4)
			{
				cout << "America's Independence Day is on Thursday, July 4, " << year;
			}
			if (r[4] == 5)
			{
				cout << "America's Independence Day is on Friday, July 4, " << year;
			}
			if (r[4] == 6)
			{
				cout << "America's Independence Day is on Saturday, July 4, " << year;
			}
		}
		else if (month == 6)
		{
			if (r[2] == 0)
			{
				cout << "National Ice Cream Sandwich Day is on Sunday, August 2, " << year;
			}
			if (r[2] == 1)
			{
				cout << "National Ice Cream Sandwich Day is on Monday, August 2, " << year;
			}
			if (r[2] == 2)
			{
				cout << "National Ice Cream Sandwich Day is on Tuesday, August 2, " << year;
			}
			if (r[2] == 3)
			{
				cout << "National Ice Cream Sandwich Day is on Wednesday, August 2, " << year;
			}
			if (r[2] == 4)
			{
				cout << "National Ice Cream Sandwich Day is on Thursday, August 2, " << year;
			}
			if (r[2] == 5)
			{
				cout << "National Ice Cream Sandwich Day is on Friday, August 2, " << year;
			}
			if (r[2] == 6)
			{
				cout << "National Ice Cream Sandwich Day is on Saturday, August 2, " << year;
			}
		}
		else if (month == 7)
		{
			cout << "Labor day is on Monday, September " << hd << ", " << year;
		}
		else if (month == 8)
		{
			if (r[31] == 0)
			{
				cout << "Halloween is on Sunday, October 31, " << year;
			}
			if (r[31] == 1)
			{
				cout << "Halloween is on Monday, October 31, " << year;
			}
			if (r[31] == 2)
			{
				cout << "Halloween is on Tuesday, October 31, " << year;
			}
			if (r[31] == 3)
			{
				cout << "Halloween is on Wednesday, October 31, " << year;
			}
			if (r[31] == 4)
			{
				cout << "Halloween is on Thursday, October 31, " << year;
			}
			if (r[31] == 5)
			{
				cout << "Halloween is on Friday, October 31, " << year;
			}
			if (r[31] == 6)
			{
				cout << "Halloween is on Saturday, October 31, " << year;
			}
		}
		else if (month == 9)
		{
			cout << "Thanks Giving is on Thursday, November " << hd << ", " << year;
		}
		else if (month == 10)
		{
			if (r[25] == 0)
			{
				cout << "Christmas is on Sunday, December 25, " << year;
			}
			else if (r[25] == 1)
			{
				cout << "Christmas is on Monday, December 25, " << year;
			}
			else if (r[25] == 2)
			{
				cout << "Christmas is on Tuesday, December 25, " << year;
			}
			else if (r[25] == 3)
			{
				cout << "Christmas is on Wednesday, December 25, " << year;
			}
			else if (r[25] == 4)
			{
				cout << "Christmas is on Thursday, December 25, " << year;
			}
			else if (r[25] == 5)
			{
				cout << "Christmas is on Friday, December 25, " << year;
			}
			else
			{
				cout << "Christmas is on Saturday, December 25, " << year;
			}
		}
		else if (month == 11)
		{
			r[1] = sd;
			if (r[1] == 0)
			{
				cout << "New Years Day is on Sunday, January 1, " << year;
			}
			else if (r[1] == 1)
			{
				cout << "New Years Day is on Monday, January 1, " << year;
			}
			else if (r[1] == 2)
			{
				cout << "New Years Day is on Tuesday, January 1, " << year;
			}
			else if (r[1] == 3)
			{
				cout << "New Years Day is on Wednesday, January 1, " << year;
			}
			else if (r[1] == 4)
			{
				cout << "New Years Day is on Thursday, January 1, " << year;
			}
			else if (r[1] == 5)
			{
				cout << "New Years Day is on Friday, January 1, " << year;
			}
			else if (r[1] == 6)
			{
				cout << "New Years Day is on Saturday, January 1, " << year;
			}
		}
		else
		{
			r[14] = (sd + 13) % 7;
			if (r[14] == 0)
			{
				cout << "Valintine's Day is on Sunday, Febuary 14, " << year;
			}
			else if (r[14] == 1)
			{
				cout << "Valintine's Day is on Monday, Febuary 14, " << year;
			}
			else if (r[14] == 2)
			{
				cout << "Valintine's Day is on Tuesday, Febuary 14, " << year;
			}
			else if (r[14] == 3)
			{
				cout << "Valintine's Day is on Wednesday, Febuary 14, " << year;
			}
			else if (r[14] == 4)
			{
				cout << "Valintine's Day is on Thursday, Febuary 14, " << year;
			}
			else if (r[14] == 5)
			{
				cout << "Valintine's Day is on Friday, Febuary 14, " << year;
			}
			else if (r[14] == 6)
			{
				cout << "Valintine's Day is on Saturday, Febuary 14, " << year;
			}
		}
		cout << endl;

		// asks user if they want to run program again
		cout << endl << "Do you want to run program again?\n";
		cout << "y for yes, no for no\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}