#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;


int getN(int bit) {
	long double c = 1;
	int n=2;

	while (bit) {
		//cout << bit << " " << c << " " << n << "\r";
		while (c < (LDBL_MAX/2) && bit) {
			c *= 2;
			bit--;
		}
		while (c > n) {
			c /= n;
			n++;
		}
		if (c == n) {
			c = 1;
			n++;
		}
	}

	return n-1;

}

void main() {
	int n;
	cout << "{";
	for (int i =0; i < 31; i++) {
		cout << getN(4 * pow(2,i)) <<","<< endl;
	}
	cout << "}";
	int tb[] = {3, 5,
		8,
		12,
		20,
		34,
		57,
		98,
		170,
		300,
		536,
		966,
		1754,
		3210,
		5910,
		10944,
		20366,
		38064,
		71421,
		134480,
		254016,
		481176,
		913846,
		1739680,
		3318996,
		6344666,
		12150874,
		23310032,
		44787927,
		86181405,
		86181405,
	};
	while (cin >> n) {
		//int bit = 4 * pow(2, ((n - 1900) / 10));
		//cout << getN(bit) << endl;
		cout << tb[(n - 1900) / 10] << endl;
	}
}