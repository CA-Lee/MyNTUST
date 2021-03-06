#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
void printhighest(map<string, int>& board) {
	int max = 0;
	string maxn;
	for (auto i : board) {
		if (i.second > max) {
			max = i.second;
			maxn = i.first;
		}
	}
	cout << maxn << endl << max << endl;
	board.erase(maxn);
}

void main() {
	string fname;
	while (cin >> fname) {
		ifstream f(fname);
		string name;
		int score;
		map<string, int> board;
		while (f>>name>>score)
		{
			board[name] = score;
		}
		printhighest(board);
		printhighest(board);

		printhighest(board);

	}
}