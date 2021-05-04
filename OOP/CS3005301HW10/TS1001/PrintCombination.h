#pragma once
#include <iostream>
#include <string>

using namespace std; 

void PrintCombination(int source[], int count, int get, const string lead = "") {
	if (get == 1) {
		for (int i = 0; i < count; i++)cout << lead << source[i] << endl;
	}
	else {
		for (int i = 1; i <= (count - get)+1; i++) {
			PrintCombination(source + i, count - i, get - 1,lead+ to_string(source[i - 1]) + " ");
		}
	}
}