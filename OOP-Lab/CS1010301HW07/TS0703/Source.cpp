#include <iostream>
#include <string>

using namespace std;

void main() {
	string nums[] = {
		"1111110",
		"0110000",
		"1101101",
		"1111001",
		"0110011",
		"1011011",
		"1011111",
		"1110000",
		"1111111",
		"1111011"
	};
	string n;
	while (getline(cin, n))
	{
		string t = "";
		for (int i = 0; i < n.size();i++) {
			if (n[i] >= '0' && n[i] <= '9')t.push_back(n[i]);
		}
		n = t;

		for (auto& c : n) {
			cout << ((nums[c - '0'][0] == '1') ? " _ " : "   ");
		}
		cout << endl;
		for (auto& c : n) {
			cout << ((nums[c - '0'][5] == '1') ? "|" : " ")
				 << ((nums[c - '0'][6] == '1') ? "_" : " ")
				 << ((nums[c - '0'][1] == '1') ? "|" : " ");
		}
		cout << endl;
		for (auto& c : n) {
			cout << ((nums[c - '0'][4] == '1') ? "|" : " ")
				<< ((nums[c - '0'][3] == '1') ? "_" : " ")
				<< ((nums[c - '0'][2] == '1') ? "|" : " ");
		}
		cout << endl;
	}
}