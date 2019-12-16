// check book
// programmer: arko chatterjee
//
// purpose: 

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std; // needed for using cin and cout

struct trans
{
	char type; // type of transaction made
	float amt; // amount of transaction
};

// function prototypes
void accsum(float bb, int dnum, float depos, int wnum, float check, float bal, struct trans arrtran[], int numarr);
void transactions(float check, float depos, float bal, float serv, float bb, int dnum, int wnum, struct trans arrtran[], float gp, char g, int numarr);
void input();

void accsum(float bb, int dnum, float depos, int wnum, float check, float bal, struct trans arrtran[], int numarr)
{
	// round
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	// arithmetic
	for (int i = 1; i <= numarr; i++)
	{
		if ((arrtran[i].type == 'c') || (arrtran[i].type == 'a') || (arrtran[i].type == 'i'))
		{
			wnum++;
		}
		else if (arrtran[i].type == 'd')
		{
			dnum++;
		}
	}
	// output
	cout << "Account Summary\n";
	cout << "          Number   Amount\n";
	cout << "Begining Balence" << setw(17) << bb << endl;
	cout << "Plus Deposits" << setw(10) << dnum << setw(10) << depos << endl;
	cout << "Less Withdraw" << setw(10) << wnum << setw(10) << check << endl;
	cout << "Ending Balence" << setw(19) << bal << endl;
	for (int i = 0; i <= 50; i++)
	{
		cout << "=";
	}
	cout << endl;
}
void transactions(float check, float depos, float bal, float serv, float bb, int dnum, int wnum, struct trans arrtran[], float gp, char g, int numarr)
{
	// declare varibles
	int il;
	float ifund;
	float atm;

	// intalize varibles
	il = 0;
	atm = 0;
	ifund = 0;
	
	// round
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	// look through array and check what it is
	for (int i = 0; i <= numarr; i++)
	{
		if (arrtran[i].type == 'c')
		{
			check = check + arrtran[i].amt;
			if (check > bal - 5)
			{
				check = check - arrtran[i].amt;
				arrtran[i].amt = 10;
				arrtran[i].type = 'i';
				ifund = ifund + 10;
			}
		}
		else if (arrtran[i].type == 'd')
		{
			depos = depos + arrtran[i].amt;
		}
		else if (arrtran[i].type == 'i')
		{
			ifund = ifund + 10;
		}
		else if (arrtran[i].type == 'a')
		{
			atm = atm + arrtran[i].amt;
		}
		else if (arrtran[i].type != 'e')
		{
			
		}
		else if (arrtran[i].type != '/0')
		{
			
		}
		else
		{
			il = 1;
		}
	}

	//out put
	cout << endl;
	cout << "Transaction                Amount     Balance\n";
	cout << endl;
	cout << "Beginning Balance" << setw(15) << bal << setw(10) << bal << endl;
	bal = bal - check;
	cout << "Checks" << setw(26) << check << setw(10) << bal << endl;
	bal = bal + depos;
	cout << "Deposit" << setw(25) << depos << setw(10) << bal << endl;
	bal = bal - serv;
	cout << "Service charge" << setw(18) << serv << setw(10) << bal << endl;
	if (atm > 0)
	{
		bal = bal - atm;
		cout << "ATM Withdraw" << setw(20) << atm << setw(10) << bal << endl;
	}
	if (ifund > 0)
	{
		bal = bal - ifund;
		cout << "Insufficient Funds" << setw(14) << ifund << setw(10) << bal << endl;
	}
	if (il == 1)
	{
		cout << "Illegal Transaction Code\n";
	}
	cout << endl;
	if (g == 'y')
	{
		if (bal >= gp)
		{
			cout << "Congradulations you have reached your goal of $" << gp << endl;
		}
		else
		{
			cout << "You did not reach your goal of $" << gp << endl;
		}
		cout << endl;
	}
	for (int i = 0; i <= 50; i++)
	{
		cout << "=";
	}
	cout << endl;
	accsum(bb, dnum, depos, wnum, check, bal, arrtran, numarr);
}
void input()
{
	// declare varibles
	char ans;
	char toa;
	float bal;
	char etran;
	int i;
	int aot;
	float check;
	float trans;
	float depos;
	float serv;
	float bb;
	int dnum;
	int wnum;
	float ifund;
	float gp;
	char g;
	struct trans arrtran[100000];
	int numarr;

	// input
	cout << "Welcome to Bank of Arko\n";
	cout << "What type of account are you planning on using?\n";
	cout << "c for checking account\n";
	cout << "s for savings account (provides 15% interest on each deposit)\n";
	cin >> toa;
	cout << "Please Enter this month's transactions:\n";
	cout << "Balance: $";
	cin >> bal;

	// intalize varible
	wnum = 0;
	dnum = 0;
	bb = bal;
	serv = 5;
	check = 0;
	depos = 0;
	gp = 0;

	// round
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	// arithmetic
	i = 0;
	do
	{
		i++;
		cout << "Transaction: ";
		cin >> arrtran[i].type;
		if (arrtran[i].type != 'e')
		{
			cout << "Amount: ";
			cin >> arrtran[i].amt;
			if (arrtran[i].type == 'd')
			{
				if (toa == 's')
				{
					arrtran[i].amt = arrtran[i].amt * 1.15;
				}
			}
		}
	} while (arrtran[i].type != 'e');
	numarr = i;
	cout << "Is there a certain goal for the amount of money you would like to have?(y/n)\n";
	cin >> g;
	if (g == 'y')
	{
		cout << "How much is it?\n";
		cin >> gp;
	}
	transactions(check, depos, bal, serv, bb, dnum, wnum, arrtran, gp, g, numarr);
}
int main()
{
	// varible declaration
	char ans;
	
	system("color 03");
	// loop
	do
	{
		input();
		
		//run program again
		cout << endl;
		cout << endl;
		cout << "    888888888888888888888" << endl;
		cout << "  s 88 ooooooooooooooo 88     s 888888888888888888888888888888888888888888888" << endl;
		cout << "  S 88 888888888888888 88    SS 888888888888888888888888888888888888888888888" << endl;
		cout << " SS 88 888888888888888 88   SSS 8888                               - --+ 8888" << endl;
		cout << " SS 88 ooooooooooooooo 88  sSSS 8888  | /  |  | |\\  /| |\\  /| |-- |-\\  | 8888" << endl;
		cout << "sSS 88 888888888888888 88 SSSSS 8888  |<   |  | | \\/ | | \\/ | |-- | /    8888" << endl;
		cout << "SSS 88 888888888888888 88 SSSSS 8888  | \\   --  |    | |    | |-- |-\\    8888" << endl;
		cout << "SSS 88 ooooooooooooooo 88 SSSSS 8888           --- /--                   8888" << endl;
		cout << "SSS 88 888888888888888 88 SSSSS 8888            |  \\-\\                   8888" << endl;
		cout << "SSS 88 888888888888888 88 SSSSS 8888           --- --/  ___              8888" << endl;
		cout << "SSS 88 oooooooooo      88 SSSSS 8888        /--\\  /--\\  |  \\             8888" << endl;
		cout << "SSS 88 8888888888 .::. 88 SSSSS 8888        |  |  |  |  |   |            8888" << endl;
		cout << "SSS 88 oooooooooo :::: 88 SSSSS 8888        |  _  |  |  |   |            8888" << endl;
		cout << "SSS 88 8888888888  `'  88 SSSSS 8888        \\--|  \\__/  |__/             8888" << endl;
		cout << "SSS 88ooooooooooooooooo88  SSSS 8888                                     8888" << endl;
		cout << "SSS 888888888888888888888__SSSS 8888                                     8888__" << endl;
		cout << "SSS |   *  *  *   )8c8888  SSSS 888888888888888888888888888888888888888888" << endl;
		cout << "SSS 888888888888888888888.  SSS 8888888888888888888888888888888888888888" << endl;
		cout << "SSS 888888888888888888888 \_ SSsssss oooooooooooooooooooooooooooo ssss" << endl;
		cout << "SSS 888888888888888888888  \\   __SS 88+-8+-88============8-8==88 S" << endl;
		cout << "SSS 888888888888888888888-. \\  \  S 8888888888888888888888888888" << endl;
		cout << "SSS 888888888888888888888  \\\  \\       `.__________.'      ` ." << endl;
		cout << "SSS 88O8O8O8O8O8O8O8O8O88  \\.   \\______________________________`_." << endl;
		cout << "SSS 88 Arko Swag 8O8O8O88 \\  '.  \|________________________________|" << endl;
		cout << "  S 888888888888888888888 /~          ~~~~~-----~~~~---.__" << endl;
		cout << " .---------------------------------------------------.    ~--." << endl;
		cout << endl;
		cout << endl;
		cout << "Do you want to run program again(y/n)?\n";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}

