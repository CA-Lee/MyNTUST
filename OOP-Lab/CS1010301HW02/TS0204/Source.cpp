#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void main() {
	int n;
	while (cin >> n) {
		vector<map<string, string>> db;
		map<string, int> max;
		for (int i = 0; i < n; i++) {
			db.push_back({});
			cin >> db[i]["name"];
			cin >> db[i]["sal"];
			cin >> db[i]["awr"];
			for (auto d : db[i]) {
				if (d.second.length() > max[d.first])max[d.first] = d.second.length();
			}
		}
		for (auto i : db) {
			cout <<right
				<< setw(max["name"]) << i["name"] <<"|  "
				<< setw(max["sal"]) << i["sal"] <<"|  "
				<< setw(max["awr"]) << i["awr"] << endl;
		}
	}
}