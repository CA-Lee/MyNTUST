#include "Month.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	month = 1;
	vector<string> msa = {"", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	string ms = string({ first,second,third });
	for (int i = 1; i < msa.size(); i++) {
		if (msa[i] == ms) {
			month = i;
			break;
		}
	}
}

Month::Month(int monthInt)
{
	if (!(monthInt > 0 && monthInt < 13)) {
		monthInt = 1;
	}
	month = monthInt;
}


Month::~Month()
{
}

void Month::inputInt()
{
	cin >> month;
	if (!(month > 0 && month < 13)) {
		month = 1;
	}
}

void Month::inputStr()
{
	char f, s, t;
	cin >> f >> s >> t;
	vector<string> msa = { "", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	string ms = string({ f,s,t });
	for (int i = 1; i < msa.size(); i++) {
		if (msa[i] == ms) {
			month = i;
			break;
		}
	}
}

void Month::outputInt()
{
	cout << month;
}

void Month::outputStr()
{
	vector<string> msa = { "", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	cout << msa[month];
}

Month Month::nextMonth()
{
	return Month(month%12+1);
}
