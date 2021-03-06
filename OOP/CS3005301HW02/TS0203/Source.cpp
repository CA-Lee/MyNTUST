#include <iostream>
#include <string>

using namespace std;

void main() {
	string s;
	while (cin>>s)
	{
		int n = 0;
		while ((n * n) < s.size())n++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = i + n*j;
				if (x < s.size()) {
					cout << s[x];
				}
			}
			cout << endl;
		}
	}
}