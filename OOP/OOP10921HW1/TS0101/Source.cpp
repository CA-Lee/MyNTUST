#include <iostream>
#include <iomanip>

using namespace std;

void main() {
	double n;
	while (cin>>n)
	{
		double g = n / 2, pre_g = n / 2;
		while (true)
		{
			double r = n / g;
			g = (g + r) / 2;
			if (abs(pre_g - g) < 0.01) {
				cout << fixed << setprecision(2) << g << endl;
				break;
			}
			else
			{
				pre_g = g;
			}

		}



	}
}