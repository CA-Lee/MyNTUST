#pragma once
#include "Document.h"

class File : public Document {
	string pathname;
public:
	File() {
		pathname = "";
	}
	File(string t, string p) :Document(t) { pathname = p; }
	string getPathname() { return pathname; }
	void setPathname(string p) { pathname = p; }
	File& operator=(File f) {
		setText(f.getText());
		pathname = f.getPathname();
		return *this;
	}
};