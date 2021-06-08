#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Carriage {
	string name;
	int passengerNum;
	string* passengerName;
public:
	Carriage* next;
	int getPassengerNum() const { return passengerNum; }
	string getName() const { return name; }
	void printPassenger() const  {
		for (int i = 0; i < passengerNum; i++) {
			if(i==0)cout<< passengerName[i];else cout << " " << passengerName[i] ;
		}
		cout << endl;
	}
	Carriage(string _name, int _passengerNum, string* _passengerName) {
		name = _name;
		passengerNum = _passengerNum;
		passengerName = _passengerName;
		next = nullptr;
	}
	~Carriage() {

	}
};

class Train {
public:
	//Carriage* first;
	Carriage* root;

	void pushCarriage(string name, int passengerNum, string* passengerName) {
		Carriage* newc = new Carriage(name, passengerNum, passengerName);
		Carriage* head = root;
		if (head == nullptr) {
			head = newc;
			root = newc;
			return;
		}
		while (head->next != nullptr)
		{
			head = head->next;
		}
		head->next = newc;
	}
	void checkPassenger(string name) const {
		Carriage* head = root;
		while (head != nullptr) {
			if (head->getName() == name)
			{
				head->printPassenger();
				return;
			}
			head = head->next;
		}

		cout << "Carriage does not exist!" << endl;

	}
	void deleteCarriage(string name) {
		Carriage* head = root;
		Carriage* pre = head;
		while (head != nullptr) {
			if (head->getName() == name)
			{
				pre->next = head->next;
				delete head;
				cout << "Delete Carriage!" << endl;
				return;
			}
			pre = head;
			head = head->next;
		}
		cout << "Carriage does not exist!" << endl;
	}
	Carriage* getCarriage(string name) const {
		Carriage* head = root;
		while (head != nullptr) {
			if (head->getName() == name)
			{
				
				return head;
			}
			head = head->next;
		}

		cout << "Carriage does not exist!" << endl;
		return nullptr;
	}
	Train() {
		root = nullptr;
	}
};