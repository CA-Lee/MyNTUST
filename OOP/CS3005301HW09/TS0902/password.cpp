#include <iostream>
#include "password.h"
using namespace std;

namespace {
	string password;
	bool isValid() {
		if (password.size() < 8)return false;
		int c = 0;
		for (auto& i : password) {
			if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))c++;
		}
		if (c == password.size())return false;
		return true;
	}
}

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}

	string getPassword()
	{
		return password;
	}
}