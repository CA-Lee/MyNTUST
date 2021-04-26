#include <iostream>
#include "user.h"
using namespace std;

namespace {
	string username;
	bool isValid() {
		if(username.size() != 8)return false;
		int c = 0;
		for (auto& i : username) {
			if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))c++;
		}
		if (c != username.size())return false;
		return true;
	}
}

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}