#include <iostream>

using namespace std;

void main() {
	unsigned long long s;
	while (cin>>s)
	{
		unsigned long long m = s / 60;
		s = s % 60;
		unsigned long long h = m / 60;
		m %= 60;
		cout << h << " hours " << m << " minutes and " << s << " seconds" << endl;
	}
}