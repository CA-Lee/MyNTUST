#pragma once
#include <string>
#include "Diary.h"
#include <iostream>

using namespace std;

class Creature;

class Attr {
public:
	string attr_name;
	Creature * creature;
	int value;
	Attr operator=(int n);
	Attr operator+=(int n);
	Attr operator-=(int n);
	void update_creature(Creature& _c);
	Attr(string _attr_name, Creature& _creature);
};

class Creature {
public:
	string day = "";
	string name;
	Diary diary;
	vector<Attr> attrs;
	Creature(string _name);
	Creature(string _name, Creature base);
	Attr& operator[](string k);
	void PrintStatus();
	void PrintLog();
};


Creature::Creature(string _name) {
	name = _name;
	diary = Diary();
	attrs = {};
}
Creature::Creature(string _name, Creature base) {
	name = _name;
	diary = Diary();
	attrs = base.attrs;
	for (auto& i : attrs) {
		i.update_creature(*this);
	}
}
Attr& Creature::operator[](string k) {
	if (day != Diary::day) {
		diary.log.push_back("Day " + Diary::day);
		day = Diary::day;
	}
	for (auto& i : attrs) {
		if (i.attr_name == k)return i;
	}
	attrs.push_back(Attr(k, *this));
	return attrs[attrs.size()-1];
}
void Creature::PrintStatus() {
	if (day != Diary::day) {
		diary.log.push_back("Day " + Diary::day);
		day = Diary::day;
	}
	cout << name << "'s status:" << endl;
	for (auto& i : attrs) {
		if(i.value)cout << i.attr_name << " * " << i.value << endl;
	}
	cout << endl;
}
void Creature::PrintLog() {
	if (day != Diary::day) {
		diary.log.push_back("Day " + Diary::day);
		day = Diary::day;
	}
	cout << name << "'s log:" << endl;
	for (auto& i : diary.log) {
		cout << i << endl;
	}
	cout << endl;
}

Attr Attr::operator=(int n) {
	if (creature->day != Diary::day) {
		creature->diary.log.push_back("Day " + Diary::day);
		creature->day = Diary::day;
	}
	creature->diary.log.push_back(creature->name + "'s " + attr_name + " appeared (" + to_string(value) + " -> " + to_string(n) + ")");
	value = n;
	return (*this);
}
Attr Attr::operator+=(int n) {
	if (creature->day != Diary::day) {
		creature->diary.log.push_back("Day " + Diary::day);
		creature->day = Diary::day;
	}
	creature->diary.log.push_back(creature->name + "'s " + attr_name + " increased (" + to_string(value) + " -> " + to_string(n) + ")");
	value += n;
	return (*this);

}
Attr Attr::operator-=(int n) {
	if (creature->day != Diary::day) {
		creature->diary.log.push_back("Day " + Diary::day);
		creature->day = Diary::day;
	}
	creature->diary.log.push_back(creature->name + "'s " + attr_name + " decreased (" + to_string(value) + " -> " + to_string(n) + ")");
	value -= n;
	return (*this);

}
void Attr::update_creature(Creature& _c) {
	creature = &_c;
}
Attr::Attr(string _attr_name, Creature& _creature) {
	attr_name = _attr_name;
	creature = &_creature;
	value = 0;
}
