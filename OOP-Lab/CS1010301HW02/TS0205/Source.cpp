#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct big_int
{
	string value;
	
	bool is_num() {
		for (char c : this->value) {
			if (c < '0' || c > '9')return false;
		}
		return true;
	}

	big_int operator+(big_int& a) {
		assert(this->is_num());
		assert(a.is_num());
		big_int res;
		
		int carry = 0;
		auto c = this->value.rbegin(),	d = a.value.rbegin();
		while (c != this->value.rend() && d != a.value.rend()) {
			res.value.insert(0, to_string( (*c - '0' + *d - '0'+ carry) %10   ));
			carry = ( *c - '0' + *d - '0' + carry ) / 10;
			c++; 
			d++;
		}

		if (c != this->value.rend()) {
			while (c != this->value.rend()) {
				res.value.insert(0, to_string((*c - '0' + carry) % 10 ));
				carry = (*c - '0' + carry) / 10;
				c++;
			}
			if (carry) {
				res.value.insert(0, to_string(carry));
			}
			return res;
		}
		else if (d != a.value.rend()) {
			while (d != a.value.rend()) {
				res.value.insert(0, to_string((*d - '0' + carry) % 10));
				carry = (*d - '0' + carry) / 10;
				d++;
			}
			if (carry) {
				res.value.insert(0, to_string(carry));
			}
			return res;
		}
		else
		{
			if (carry) {
				res.value.insert(0, to_string(carry));
			}
			return res;
		}
		
	}

};

void main() {
	int n;
	while (cin>>n)
	{
		for (int i = 0; i < n; i++) {
			big_int a, b;
			cin >> a.value >> b.value;
			if (a.is_num() && b.is_num()) {

				cout << (a + b).value << endl;
			}
			else {
				cout << "Not a valid number, please try again." << endl;
			}
		}
	}
}