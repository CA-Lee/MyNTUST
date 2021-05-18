#include <iostream>
#include <vector>
#include <string>

using namespace std;

void main() {
	unsigned int m, n;
	while (cin >> m >> n) {
		vector<unsigned char> mem(m, 0);
		for (unsigned int i = 0; i < n; i++) {
			string cmd;
			unsigned int pos;
			string type;
			cin >> cmd >> pos >> type;

			if ((pos >= m) ||
				(type == "short" && pos + 1 >= m) ||
				(type == "int" && pos + 3 >= m)) {
				cout << "Violation Access." << endl;
				if (cmd == "Get")continue;
			}

			if (cmd == "Get") {
				if (type == "char") {
					unsigned char* p = &mem[pos];
					cout << char(*p) << endl;
				}
				else if (type == "short") {
					unsigned short* p = (unsigned short*)&mem[pos];
					cout << unsigned int(*p) << endl;
				}
				else if (type == "int") {
					unsigned int* p = (unsigned int*)&mem[pos];
					cout << unsigned int(*p) << endl;
				}
				else if (type == "String") {
					while (pos < m && mem[pos] != '\0')cout << mem[pos++];
					cout << endl;
				}
			}
			else if (cmd == "Set") {
				if (type == "String") {
					string s;
					getline(cin, s);
					while (s[0] == ' ')s = s.substr(1, s.size() - 1);
					s += '\0';
					for (unsigned int i = 0; pos < m && i < s.size(); i++, pos++) {
						mem[pos] = s[i];
					}
					if (pos == m)cout << "Violation Access." << endl;
				}
				else {
					unsigned int n;
					cin >> n;
					if (type == "char") {

						mem[pos] = n & 0xff;
					}
					else if (type == "short") {
						if (m - pos < 2) {
							mem[pos] = n & 0xff;
						}
						else {
							unsigned short* p = (unsigned short*)&mem[pos];
							*p = n;
						}
					}
					else if (type == "int") {
						if (m - pos < 4) {
							while (pos < m) {
								mem[pos] = n & 0xff;
								n >>= 8;
								pos++;
							}
						}
						else {
							unsigned int* p = (unsigned int*)&mem[pos];
							*p = n;
						}
					}
				}
			}
		}
	}
}