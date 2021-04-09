#include "Form.h"

#include<string>
#include <fstream>
#include <iostream>
using namespace std;

void Form::SetInputWord(string inputWord) {
	key = inputWord;
}
void Form::ProcessInputWord(){
	// process input
	keysum = vector<int>(26);
	for (auto i : key) {
		if (i >= 'A' && i <= 'Z') {
			i -= 'A' - 'a';
		}
		keysum[i - 'a']++;
	}
}
void Form::SetFileName(string fileName) {
	wordfile = fileName;
}
void Form::Load_CompareWord() {
	fstream f(wordfile);
	string i;
	while (f >> i) {
		vector<int> sum = keysum;
		int flag = 0;
		for (auto c : i) {
			if (c >= 'A' && c <= 'Z') {
				c -= 'A' - 'a';
			}
			sum[c - 'a']--;
			if (sum[c - 'a'] < 0)flag++;
		}
		if(!flag)wl.push_back(i);
	}
}
void Form::PrintFoundWords() {
	for (auto& i : wl) {
		cout << i << endl;
	}
}
