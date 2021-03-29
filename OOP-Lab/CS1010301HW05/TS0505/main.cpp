#include<iostream>
#include"Point.h"
using namespace std;
int main(void) {
	Point point;
	point.Set(0, 5);
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
	point.Reflect();
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
	point.Move(1, 2);
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
	point.Rotate();
	cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
	Point copy = point;
	cout << "Copy point:" << endl;		
	cout << copy. GetHorizontal() << " " << copy. GetVertical() << endl;
	return 0;
}
