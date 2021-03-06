#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void main() {
	int n;
	while (cin >> n) {
		vector<double> ns;
		for (int i = 0; i < n; i++) {
			ns.push_back(0);
			cin >> ns[i];
		}
		double ave =0;
		for (double i : ns) {
			ave += i;
		}
		ave /= ns.size();
		double std = 0;
		for (double i : ns) {
			std += (i - ave) * (i - ave) / ns.size();
		}
		std = sqrt(std);

		cout << "Average:" << ave << "\tStandard deviation:" << std << endl;
	}

}