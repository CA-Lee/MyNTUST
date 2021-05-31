#pragma once
#include <iostream>
#include <string>
using namespace std;


class School {
	string name;
public:
	int studentAmount;
	int studentAmountNextYear;
	School(string _name, float _studentAmount) {
		name = _name;
		studentAmount = _studentAmount;
		studentAmountNextYear = _studentAmount;
	}
	void admissions(float amount) {
		if (amount >= 0) {

			studentAmount += amount;
		}
	}
	virtual void dropouts(float amount) {
		if (amount >= 0 && amount <= studentAmount) {

			studentAmount -= amount;
		}
	}
	void transfer(float amount, School& toSchool) {
		if (amount >= 0 && amount <= studentAmount) {
			dropouts(amount);
			toSchool.admissions(amount);
		}
	}
	friend ostream& operator << (ostream& os, School s) {
		os << s.name << "\t" << s.studentAmount << "\t" << s.studentAmountNextYear;
		return os;
	}
};

class PrivateSchool : public School {
	bool pen = false;
public:
	PrivateSchool(string a, float b) :School(a, b) {};
	void dropouts(float amount) override {
		if (amount >= 0 && amount <= studentAmount) {

			studentAmount -= amount;
			if (pen) studentAmountNextYear -= 100;
			else pen = true;
		}
	}
};

class PublicSchool : public School {
public:
	PublicSchool(string a, float b) :School(a, b) {};
	void apply_growth() {
		studentAmountNextYear *= 1.05;
	}
	void dropouts(float amount) override {
		if (amount >= 0 && amount <= studentAmount) {

			studentAmount -= amount;
			if (amount > 100) {
				studentAmountNextYear = int(studentAmountNextYear * 0.95);
			}
		}
	}
};