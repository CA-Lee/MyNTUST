#include "Atoi.h"

Atoi::Atoi() {
	beTrans = "";
}
Atoi::Atoi(string s) {
	beTrans = s;
}
void Atoi::SetString(string s) {
	beTrans = s;
}
const string Atoi::GetString() {
	return beTrans;
}
int Atoi::Length() {
	return beTrans.size() + (beTrans[0] == '-' ? -1:0);
}
bool Atoi::IsDigital() {
	for (auto& c : beTrans) {
		if (!(c == '-' || (c >= '0' && c <= '9')))return false;
	}
	return true;
}
int Atoi::StringToInteger() {
	//return stol(beTrans); // This works
	int n = 0;
	for (int i = 0; i < beTrans.size(); i++) {
		if (i == 0 && beTrans[i] == '-')continue;
		n *= 10;
		n += beTrans[i] - '0';
	}
	return beTrans[0] == '-'?-n:n;
}