#include <iostream>
#include <map>
#include <string>


using namespace std;

int main() {
	int kn, tn;
	while (cin>>kn>>tn)
	{
		if (!kn && !tn)break;
		map<char, map<char,bool>> book;
		for (char c = 'a'; c <= 'z'; c++) {
			for (char d = 'a'; d <= 'z'; d++) {
				book[c][d] = false;
				if (c == d)book[c][d] = true;
			}
		}
		for (int i = 0; i < kn; i++) {
			char a, b;
			cin >> a >> b;
			if (!(a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')) {
				cout << "ERROR" << endl;
			}
			else {
				book[a][b] = true;
			}
		}

		for (char c = 'a'; c <= 'z'; c++) {
			for (char d = 'a'; d <= 'z'; d++) {
				for (char e = 'a'; e <= 'z'; e++) {
					if (book[d][c] && book[c][e])book[d][e] = true;
				}
			}
		}

		for (int i = 0; i < tn; i++) {
			string a, b;
			cin >> a >> b;
			if (a.size() != b.size()) { cout << "no" << endl; }
			else {
				int ac=0, bc=0;
				for (int j = 0; j < a.size(); j++) {
					if (a[j] >= 'a' && a[j] <= 'z')ac++;
					if (b[j] >= 'a' && b[j] <= 'z')bc++;

				}
				if (ac != a.size() || bc != b.size()) {
					cout << "ERROR" << endl;
				}
				else {
					ac = 0;
					for (int j = 0; j < a.size(); j++) {
						if (book[a[j]][b[j]])ac++;
					}
					if (ac == a.size())cout << "yes" << endl;
					else cout << "no" << endl;
				}
			}
		}






	}
}