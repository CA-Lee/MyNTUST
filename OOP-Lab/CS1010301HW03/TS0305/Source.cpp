#include <iostream>
#include <vector>

using namespace std;

class Canvas {

public:
	int w;
	int h;
	vector<vector<char>> b;

	Canvas(int w, int h) {
		this->w = w;
		this->h = h;
		
		for (int i = 0; i < h; i++) {
			vector<char> v;
			for (int j = 0; j < w; j++) {
				v.push_back('*');
			}
			b.push_back(v);
		}
	}

	void oor() {
		cout << "Out of range." << endl << endl;
	}

	void print() {
		for (auto& r : b) {
			for (auto& c : r) {
				cout << c;
			}
			cout << endl;
		}
		cout << endl;
	}

	void s(int w, int x, int y) {
		if (x < 0 || y < 0)oor();
		if (x + w > this->w || w + y > this->h) {
			oor();
		}
		else {
			for (int i = y; i < y + w; i++) {
				for (int j = x; j < x + w; j++) {
					b[i][j] = 'X';
				}
			}
			print();
		}

	}
	void t(int w, int x, int y, string d) {
		if (d == "RU") {
			if (y >= Canvas::h || x + w > Canvas::w || y-w<-1||x<0) {
				oor();
			}
			else
			{
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w-i; j++) {
						b[y - i][x + j] = 'X';
					}
				}
				print();
			}
		}
		else if (d == "RD") {
			if (y + w > Canvas::h || x + w > Canvas::w || x < 0||y<0) {
				oor();
			}
			else
			{
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w - i; j++) {
						b[y + i][x + j] = 'X';
					}
				}
				print();
			}
		}
		else if (d == "LU") {
			if (y >= Canvas::h || x >= Canvas::w || x-w < -1 || y-w<-1) {
				oor();
			}
			else
			{
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w - i; j++) {
						b[y - i][x - j] = 'X';
					}
				}
				print();
			}
		}
		else if (d == "LD") {
			if (y + w > Canvas::h || x >= Canvas::w || x - w < -1 || y<0) {
				oor();
			}
			else
			{
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < w - i; j++) {
						b[y + i][x - j] = 'X';
					}
				}
				print();
			}
		}
	}
	void l(int sx, int sy, int ex, int ey) {
		if (sx < 0 || sy < 0 || ex < 0 || ey < 0)oor();
		if (sx >= Canvas::w || sy >= Canvas::h || ex >= Canvas::w || ey >= Canvas::h) {
			oor();
		}
		else {
			if (sx == ex || sy == ey) {
				for (int i = sy; i <= ey; i++) {
					for (int j = sx; j <= ex; j++) {
						b[i][j] = 'X';
					}
				}
			}
			else {
				for (int i = sy, j = sx; i != ey ; i+=(ey-sy)/abs(ey-sy), j+=(ex-sx)/abs(ex-sx) ){
					b[i][j] = 'X';
				}
				b[ey][ex] = 'X';
			}
			print();
		}
	}

};


void main() {
	int w, h;
	cin >> w >> h;
	Canvas cnv(w, h);
	string c;
	while (cin >> c) {
		if (c == "S") {
			int w, x, y;
			cin >> w >> x >> y;
			cnv.s(w, x, y);
		}
		else if (c=="T")
		{
			int w, x, y;
			string d;
			cin >> w >> x >> y >> d;
			cnv.t(w, x, y, d);
		}
		else if (c=="L")
		{
			int sx, sy, ex, ey;
			cin >> sx >> sy >> ex >> ey;
			cnv.l(sx, sy, ex, ey);
		}
		else if (c=="EXIT")
		{
			return;
		}
	}
}