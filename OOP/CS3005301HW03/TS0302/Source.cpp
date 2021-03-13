#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void main() {
	ifstream input("grade.txt");
	map<string, int> book { {"0", 0},{"1" , 0},{"2" , 0},{"3" ,0},{"4" , 0},{"5" , 0} };
	string a;
	while (input >> a)
	{
		book[a]++;
	}
	vector<int> keys;
	for (auto& i : book) {
		keys.push_back(stoi(i.first));
	}
	sort(keys.begin(), keys.end());
	ofstream out("grades.Output");
	for (int& k : keys) {
		out << book[to_string(k)] <<" grade(s) of "<< k << endl;
	}
}