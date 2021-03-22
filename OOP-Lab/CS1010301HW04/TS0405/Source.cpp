#include <iostream>

using namespace std;

int step(int n) {
	if (n == 1)return 1;
	if (n & 1) {
		return step(3 * n + 1) + 1;
	}
	else
	{
		return step(n >> 1) + 1;
	}
}

void main() {
	int a, b;
	while (cin>>a>>b)
	{
		int max = 0, m = a, n = b;
		if (m > n) {
			int t = m;
			m = n; n = t;
		}
		for (int i = m; i <= n;i++) {
			int p = step(i);
			if (p > max)max = p;
		}
		cout << a << " " <<  b << " " << max << endl;
	}
}