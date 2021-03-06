#include <iostream>
#include <iomanip> 
using namespace std;

void main() {
	double r;
	while (cin >> r) {
		cout << fixed << setprecision(6) << r*r*r*3.14159265358979323846  * 4 / 3  << endl;
	}
}