#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main() {
	set<string> list;
	string n;
	fstream f("name.txt");
	while (getline(f,n))
	{
		list.insert(n);
	}
	for (auto& i : list) {
		cout << i << endl;
	}
}