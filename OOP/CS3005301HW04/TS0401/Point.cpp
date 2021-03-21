#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(int v, int h)
{
	vertical += v;
	horizontal += h;
}

void Point::Rotate()
{
	int new_h = - vertical;
	int new_v = horizontal;
	horizontal = new_h;
	vertical = new_v;
}
