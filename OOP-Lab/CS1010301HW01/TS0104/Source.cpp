#include <iostream>
#include <string>


using namespace std;

void main() {
	string s;
	while (cin>>s) {
		if (s.length() > 9) {
			cout <<  s << endl;
		}
		else {
			for (int i = 0; i < 10 - s.length(); i++)cout << " ";
			cout << s << endl;
		}
	}
}