#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
private:
	int vertical;
	int horizontal;

public:
	Point()
	{
		vertical = 0;
		horizontal = 0;
	}

	void Set(int vertical, int horizontal);
	void Move(int x, int y);
	void Rotate();
	int RetrieveVertical() const { return vertical; }
	int RetrieveHorizontal() const { return horizontal; }
};

#endif //Point_H