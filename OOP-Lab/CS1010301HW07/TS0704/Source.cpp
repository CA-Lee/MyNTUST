#include <iostream>
#include <string>
#include <map>

using namespace std;

int ld(string n, string m, map<string, map<string, int>>& table) {
	if (table.find(n) != table.end()) {
		if (table[n].find(m) != table[n].end()) {
			return table[n][m];
		}
	}
	if (!(n.size() && m.size()))return n.size() + m.size();
	if (n == m)return 0;
	while (n.size() && m.size()) {
		if ((n[0] != m[0]) && (n[n.size() - 1] != m[m.size() - 1]))break;
		if (n[0] == m[0]) {
			n.erase(n.begin());
			m.erase(m.begin());
		}
		if (n[n.size() - 1] == m[m.size() - 1]) {
			n.pop_back();
			m.pop_back();
		}
	}
	if (!(n.size() && m.size()))return n.size() + m.size();
	int a = ld(n.substr(0,n.size()-1), m, table),
		b = ld(n, m.substr(0,m.size()-1), table),
		c = ld(n.substr(0, n.size() - 1), m.substr(0, m.size() - 1), table);
	table[n][m] = min(min(a, b), c) + 1;
	return table[n][m];
}

void main() {
	string n, m;
	map<string, map<string, int>> table;
	while (getline(cin, n)) {
		getline(cin, m);
		cout << ld(n, m, table) << endl;
	}
}