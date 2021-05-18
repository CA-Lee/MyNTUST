#pragma once
#include <string>

using namespace std;

class Document {
	string text;
public:
	Document() {
		text = "";
	}
	Document(string s) {
		text = s;
	}
	string getText() const { return text; }
	void setText(string t) { text = t; }
	Document& operator=(Document d) {
		text = d.text;
		return *this;
	}
};