#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void main() {
	string x;
	char c;
	int m, n;
	while (cin >> x >> m >> n >> c)
	{
		if (x.find(".") != string::npos) {
			double dx = stod(x.substr(0, x.find(".") + 1 + n));
			cout << setw(m) << setfill(c) << fixed << setprecision(n) << dx << endl;
		}
		else
		{
			double dx = stod(x);
			cout << setw(m) << setfill(c) << fixed << setprecision(n) << dx << endl;
		}
	}
}