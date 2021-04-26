#include <iostream>
#include <string>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;


	double a[] = { 0 };
	cout << "0==" << Polynomial(a, 1).mySize() << endl;

	double b[] = { 0 , 1, 2 ,4 ,7,0 };
	cout << "5==" << Polynomial(b, 6).mySize() << endl; 

	double aa[] = { 1 };
	cout << "1==" << Polynomial(aa, 1).mySize() << endl; 
	
	double m1[] = { 0 };
	double m2[] = { 3 ,4 ,1 };
	Polynomial pm1(m1, 0), pm2(m2, 3);

	cout << (pm1 - pm2).mySize() << endl;
	cout << (pm2 - pm1).mySize() << endl;
	cout << (pm1 - 3).mySize() << endl;
	//cout << (0 - pm1).mySize() << endl;


	return 0;
}