#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void main() {
		map<string, int> book;
		string a;
		while (cin>>a)
		{
			book[a]++;
		}
		vector<int> keys;
		for (auto& i : book) {
			keys.push_back(stoi(i.first));
		}
		sort(keys.begin(), keys.end(), greater<int>());
		cout << "N\tcount" << endl;
		for (int& k : keys) {
			cout << k  << "\t" << book[to_string(k)] << endl;
		}

}