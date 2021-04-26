#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		if (!m && !n) {
			break;
		}
		map<char, map<char, bool>> dict;
		for (char c = 'a'; c <= 'z'; c++) {
			for (char d = 'a'; d <= 'z'; d++) {
				dict[c][d] = (c==d?1:0);
			}
		}
		for (int i = 0; i < m; i++) {
			char from, to;
			cin >> from >> to;
			dict[from][to] = true;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			for (char d = 'a'; d <= 'z'; d++) {
				if (dict[d][c] && d!=c) {
					for (char e = 'a'; e <= 'z'; e++) {
						dict[d][e] = dict[d][e] || dict[c][e];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (a.length() != b.length())cout << "no" << endl;
			else {
				bool match = true;
				for (int j = 0; j < a.size();j++) {
					match = match && dict[a[j]][b[j]];
				}
				cout << (match ? "yes" : "no") << endl;
			}
		}
	}
}