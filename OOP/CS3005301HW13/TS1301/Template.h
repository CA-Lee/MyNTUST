#pragma once

template<class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	found = false;
	int m = (first + last) / 2;
	while (a[m]!=key&&first!=last)
	{
		if (a[m] > key)last = m-1;
		if (a[m] < key)first = m+1;
		m = (first + last) / 2;
	}
	if (a[m] == key) {
		location = m;
		found = true;
	}
}

template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
	location = (first + last) / 2;
	if (a[location] == key)found = true;
	else if (first == last)found = false;
	else if (a[location] > key)RecBinarySearch(a, first, location - 1, key, found, location);
	else if (a[location] < key)RecBinarySearch(a, location + 1, last, key, found, location);	
}
