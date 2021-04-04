#include "PrimeNumber.h"
#include <cmath>

using namespace std;
int PrimeNumber::get() { return value; }

bool is_prime(int p){
	for (int i = 2; i <= sqrt(p); i++) {
		if (!(p % i))return false;
	}
	return true;
}

PrimeNumber::PrimeNumber() {
	value = 1;
}
PrimeNumber::PrimeNumber(int _value) {
	value = _value;
}
PrimeNumber& PrimeNumber::operator++() {
	while (!is_prime(++value));
	return (*this);
}
PrimeNumber PrimeNumber::operator++(int) {
	PrimeNumber old = {value};
	while (!is_prime(++value));
	return old;

}
PrimeNumber& PrimeNumber::operator--() {
	while (!is_prime(--value));
	return (*this);

}
PrimeNumber PrimeNumber::operator--(int) {
	PrimeNumber old = { value };
	while (!is_prime(--value));
	return old;

}