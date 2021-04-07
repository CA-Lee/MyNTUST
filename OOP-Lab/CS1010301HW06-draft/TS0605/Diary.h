#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Diary;

class Diary {

public:
	vector<string> log;
	static string day;
	static void NewDay(string _day) {
		day = _day;
	}
	Diary() {
		log = {};
	}
};

string Diary::day = "";