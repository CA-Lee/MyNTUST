#include "Fraction.h"
//#include <iostream>

//using namespace std;

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	if (numerator == 0) {
		cout << 0 << endl;
		return;
	}
	//find gcd
	int gcd = numerator;
	while (numerator % gcd || denominator % gcd)gcd--;

	if (gcd == denominator) {
		cout << numerator / gcd << endl;
	}
	else {
		cout << fixed << setprecision(6) << double(numerator) / double(denominator) << endl;
	}
}

void Fraction::outputReducedFraction()
{
	if (numerator == 0) {
		cout << 0 << endl;
		return;
	}
	//find gcd
	int gcd = numerator;
	while (numerator % gcd || denominator % gcd)gcd--;

	if (gcd == denominator) {
		cout << numerator / gcd << endl;
	}
	else {
		cout << numerator / gcd << "/" << denominator / gcd << endl;
	}
}



