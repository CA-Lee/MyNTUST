#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string IE = "Input Error";
const string ISE = "Insert Error";
const string SE = "Search Error";


class StRec ;

class StRec {
public:
	static vector<StRec> db;
	std::string sign;
	std::string firstName;
	std::string lastName;
	std::string phone;

	StRec(string fn, string ln, string ph) {
		firstName = fn;
		lastName = ln;
		phone = ph;
		sign = fn + ln + ph;
	}

	static bool verify(string fn, string ln, string ph) {
		if (fn.size() > 25 || ln.size() > 30 || ph.size() > 15) {
			cout << IE << endl;
			return false;
		}
		else {
			//check p is int
			for(auto& c:ph){
				if (!(c == '+' || c == '-' || (c >= '0' && c <= '9'))) {
					cout << IE << endl;
					return false;
				}
			}
			return true;
		}
	}
	static int find(std::string sign) {
		for (int i = 0; i < db.size(); i++) {
			if (db[i].sign == sign)return i;
		}
		return -1;
	}
	static void print() {
		for (auto& i : db) {
			cout << i.firstName << " " << i.lastName << " " << i.phone << endl;
		}
	}
};

vector<StRec> StRec::db;

int main() {
	string cmd;
	while (cin>>cmd)
	{
		if (cmd == "insert") {
			string fn, ln, ph;
			cin >> fn >> ln >> ph;
			if (StRec::verify(fn, ln, ph)) {
				if (StRec::db.size() > 9 || StRec::find(fn + ln + ph) != -1) {
					cout << ISE << endl;
				}
				else {
					StRec::db.push_back(StRec(fn, ln, ph));
				}
			}
		}
		else if (cmd == "search") {
			string fn, ln, ph;
			cin >> fn >> ln >> ph;
			if (StRec::verify(fn, ln, ph)) {
				int res = StRec::find(fn + ln + ph);
				cout << ((res != -1) ? to_string(res) : SE) << endl;
			}
		}
		else if (cmd=="delete")
		{
			string fn, ln, ph;
			cin >> fn >> ln >> ph;
			if (StRec::verify(fn, ln, ph)) {
				int id = StRec::find(fn + ln + ph);
				if (id == -1) {
					cout << "Delete Error" << endl;
				}
				else
				{
					StRec::db.erase(StRec::db.begin()+id);
				}
			}
		}
		else if(cmd=="print")
		{
			if (StRec::db.size()) {
				StRec::print();
			}
			else {
				cout << "Print Error" << endl;
			}
		}
		else {
			cout << IE << endl;
		}
	}
}