#pragma once
#include <string>
#include <vector>

using namespace std;

class NumberGame {
public:

	int a;
	vector<int> s;
	vector<int> alist;
	string filename;
	
	void SetInput(int);
	void ProcessInput();
	void SetFileName(string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};
