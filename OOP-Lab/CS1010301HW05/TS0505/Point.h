#include <vector>
using namespace std;

class Point {

private:
	vector<double> cor = { 0,0 };
public:
	void Set(double x,double y);
	void Move(double x, double y);
	void Rotate();
	void Reflect();
	Point();
	~Point();
	double GetHorizontal() const { return cor[0]; }
	double GetVertical() const { return cor[1]; }
};