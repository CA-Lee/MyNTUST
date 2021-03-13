#include <iostream>
#include <iomanip	>

using namespace std;

void main() {
	double in;
	while (cin>>in)
	{
		double res;
		if (in > 7000) {
			res = 230 + 0.06 * (in - 7000);
		}
		else if (in > 5250) {
			res = 142.50 + 0.05 * (in - 5250);
		}
		else if (in > 3750) {
			res = 82.5 + 0.04 * (in - 3750);
		}
		else if (in > 2250) {
			res = 37.5 + 0.03 * (in - 2250);
		}
		else if (in > 750) {
			res = 7.50 + 0.02 * (in - 750);
		}
		else {
			res = in * 0.01;
		}
		cout << fixed << setprecision(2) << res << endl;
	}
}