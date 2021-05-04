#include <iostream>
#include <fstream>

using namespace std;

bool find_word(string word, int index, string s[], bool book[][4], int x = 0, int y = 0  ) {
	if (!index) {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (s[y][x] == word[0]) {
					book[y][x] = true;
					if (find_word(word, 1, s,book, x, y))return true;
				}
			}
		}
		return false;
	}
	if (index == word.size())return true;

	for (int y1 = y - 1; y1 <= y + 1; y1++) {
		for (int x1 = x - 1; x1 <= x + 1; x1++) {
			if (y1 >= 0 && y1 < 4 && x1 >= 0 && x1 < 4) {
				if (s[y1][x1] == word[index] && !book[y1][x1]) {
					book[y1][x1] = true;
					if (find_word(word, index+1, s,book, x1, y1))return true;
				}
			}
		}
	}
	return false;
}

int main() {
	string s[4];
	while (cin>>s[0]>>s[1]>>s[2]>>s[3])
	{
		fstream f("words.txt");
		string word;
		while (f>>word)
		{
			bool book[][4] = { {false,false,false,false},{false,false,false,false},{false,false,false,false},{false,false,false,false} };
			if (find_word(word,0, s,book)) {
				cout << word << endl;
			}
		}
		cout << endl;
	}
}