#pragma once
#include <type_traits>

using namespace std;

template <class T>
double absoluteValue(T a, T b) {
	return double(a > b ? a - b : b - a);
}