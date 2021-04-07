#pragma once
#include <vector>

using namespace std;

class VecNf {

public:
	
	vector<double> val;
	VecNf() {
		val = vector<double>{};
		val.push_back(0);
	}
	VecNf(float* vals, int len) {
		val = vector<double>{};
		for (int i = 0; i < len; i++) {
			val.push_back(vals[i]);
		}
	}
	VecNf(const VecNf& rhs) {
		val = vector<double>(rhs.val);
	}
	VecNf& operator=(VecNf rhs) {
		cout << "ASSIGNMENT!!!" << endl;
		val = vector<double>(rhs.val);
		return (*this);
	}
	double& operator[](int i) {
		return val[i];
	}
	VecNf operator+(VecNf b) {
		if (val.size() != b.val.size()) {
			cout << "dimensions inconsistent" << endl;
			return VecNf();
		}
		VecNf r(*this);
		for (int i = 0; i < r.val.size();i++) {
			r.val[i] += b.val[i];
		}
		return r;
	}
	VecNf operator-(VecNf b) {
		if (val.size() != b.val.size()) {
			cout << "dimensions inconsistent" << endl;
			return VecNf();
		}
		VecNf r(*this);
		for (int i = 0; i < r.val.size(); i++) {
			r.val[i] -= b.val[i];
		}
		return r;
	}
	double operator*(VecNf b) {
		if (val.size() != b.val.size()) {
			cout << "dimensions inconsistent" << endl;
			return 0;
		}
 		double r = 0;
		for (int i = 0; i < val.size(); i++) {
			r += val[i] * b.val[i];
		}
		return r;
	}
	friend VecNf operator*(double, VecNf);
	int Size() {
		return val.size();
	}
};

VecNf operator*(double s, VecNf vec) {
	VecNf r(vec);
	for (auto& i : r.val) {
		i *= s;
	}
	return r;
}
