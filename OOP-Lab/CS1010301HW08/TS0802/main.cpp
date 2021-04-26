#include <iostream>
#include <vector>

using namespace std;

void main() {
	int ar, ac, br, bc;
	while (cin >> ar >> ac >> br >> bc) {
		vector<vector<int>> a, b;
		for (int i = 0; i < ar; i++) {
			vector<int> k;
			for (int j = 0; j < ac; j++) {
				int t;
				cin >> t;
				k.push_back(t);
			}
			a.push_back(k);
		}
		for (int i = 0; i < br; i++) {
			vector<int> k;
			for (int j = 0; j < bc; j++) {
				int t;
				cin >> t;
				k.push_back(t);
			}
			b.push_back(k);
		}
		if (ac != br) {
			cout << "Matrix multiplication failed." << endl;
			continue;
		}
		for (int i = 0; i < ar; i++) {
			for (int j = 0; j < bc; j++) {
				int sum = 0;
				for (int k = 0; k < ac; k++) {
					sum += a[i][k] * b[k][j];
				}
				cout << sum << (j<bc-1?" ":"");
			}
			cout << endl;
		}
	}
}