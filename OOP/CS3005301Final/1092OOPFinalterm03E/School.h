#pragma once
#include <string>

using namespace std;

class School {
public:
	School(string _name, int stu)
		:name(_name),studentNumber(stu),studentNumberNextYear(stu) {}
	string name;
	int studentNumber;
	int studentNumberNextYear;
	void admissions(float number) {
		if (number >= 0) {
			studentNumber += number;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
	virtual void dropouts(float number) {
		if (number >= 0 && number <= studentNumber) {
			studentNumber -= number;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
	void transfer(float number, School& toSchool) {
		if (number >= 0 && number <= studentNumber) {
			dropouts(number);
			toSchool.admissions(number);
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
	friend ostream& operator << (ostream& os, School t) {
		os << t.name << "\t" << t.studentNumber << "\t" << t.studentNumberNextYear;
		return os;
	}
};

class PrivateSchool :public School {
	bool pen = false;

public:
	PrivateSchool(string _name, int stu) :School(_name, stu) {}
	virtual void dropouts(float number)override {
		if (number >= 0 && number <= studentNumber) {
			studentNumber -= number;
			if (pen)studentNumberNextYear -= 100;
			else pen = true;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
};
class PublicSchool :public School {
public:
	PublicSchool(string _name, int stu) :School(_name, stu) {}

	void apply_growth() {
		studentNumberNextYear =double(studentNumberNextYear)* 1.05;
	}
	virtual void dropouts(float number)override {
		if (number >= 0 && number <= studentNumber) {
			studentNumber -= number;
			if (number > 100)studentNumberNextYear = double(studentNumberNextYear) * 0.95;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}

};

