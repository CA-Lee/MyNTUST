#include "Point.h"

void Point::Set(double x, double y) {
	cor[0] = x;
	cor[1] = y;
}
void Point::Move(double x, double y) {
	cor[0] += x;
	cor[1] += y;
}
void Point::Rotate() {
	auto x = cor[1];
	auto y = -cor[0];
	cor[0] = x?x:0;
	cor[1] = y?y:0;
}
void Point::Reflect() {
	cor[0] = -cor[0]? -cor[0]:0;
	cor[1] = -cor[1]? -cor[1]:0;
}
Point::Point() {

}
Point::~Point() {

}