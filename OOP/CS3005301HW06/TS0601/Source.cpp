#include "Complex.h"
#include <iostream>
#include <string>

using namespace std;

Complex::Complex() {
	realValue = 0;
	imaginaryValue = 0;
}
Complex::Complex(double r) {
	realValue = r;
	imaginaryValue = 0;
}
Complex::Complex(double r, double i) {
	realValue = r;
	imaginaryValue = i;
}

double Complex::real() { return realValue; }
double Complex::imag() { return imaginaryValue; }
double Complex::norm() { return pow(realValue * realValue + imaginaryValue * imaginaryValue, 0.5); }
double real(Complex c) { return c.realValue; }
double imag(Complex c) { return c.imaginaryValue; }
double norm(Complex c) { return pow(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue, 0.5); }

Complex Complex::operator+(Complex c) { return Complex(realValue + c.realValue, imag() + c.imag()); }
Complex Complex::operator-(Complex c) { return Complex(realValue - c.realValue, imag() - c.imag()); }
Complex Complex::operator*(Complex c) {
	return Complex(real() * c.real() - imag() * c.imag(), real() * c.imag() + imag() * c.real());
}
Complex Complex::operator/(Complex c) {
	// (a +bi )/ (c+di) = 
	// (a+bi)*(c-di)/(c^2+d^2)
	c.imaginaryValue = -c.imaginaryValue;
	Complex a = (*this) * c;
	a.realValue /= c.real() * c.real() + c.imag() * c.imag();
	a.imaginaryValue /= c.real() * c.real() + c.imag() * c.imag();

	return a;
}
Complex operator+(double d, Complex c) { return Complex(d) + c; }
 Complex operator-(double d, Complex c) { return Complex(d) - c; }
 Complex operator*(double d, Complex c) { return Complex(d) * c; }
 Complex operator/(double d, Complex c) { return Complex(d) / c; }
 bool operator==(Complex c1, Complex c2) { return c1.real() == c2.real() && c1.imag() == c2.imag(); }
 ostream& operator<<(ostream& strm, const Complex& c) {
	 strm << c.realValue << " + " << c.imaginaryValue << "*i";
	 return strm;
}
 istream& operator>>(istream& strm, Complex& c) {
	 string input;
	 getline(strm, input);
	 c.realValue = stod(input.substr(input.find('=') + 1, input.find('+') - input.find('=') + 1));
	 c.imaginaryValue = stod(input.substr(input.find('+') + 1, input.find('*') - input.find('+') + 1));
	 return strm;
}