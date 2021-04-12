#include <iostream>

using namespace std;

bool allow(int x1, int x2, int y1, int y2, int board[][8]) {

	if (abs(x1 - x2) + abs(y1 - y2) == 1) {
		return true;
	}
	
	if (x1 == x2) {
		int sum = 0;
		for (int i = min(y1,y2)+1; i < max(y1,y2); i ++) {
			sum += board[i][x1];
		}
		if (!sum) {
			return true;
		}
	}
	if (y1 == y2) {
		int sum = 0;
		for (int i =min(x1,x2)+1; i <max(x1,x2); i ++) {
			sum += board[y1][i];
		}
		if (!sum) {
			return true;
		}
	}
	return false;
}

bool tong(int x1, int x2, int y1, int y2, int board[][8]) {
	if (board[y1][x1] != board[y2][x2] || (x1 == x2 && y1 == y2) || board[y1][x1] == 0)return false;
	if(allow(x1,x2,y1,y2,board)) {
		return true;
	}
	if ((allow(x1, x1, y1, y2, board) && allow(x1, x2, y2, y2, board) && board[y2][x1] == 0) || 
		(allow(x1, x2, y1, y1, board) && allow(x2, x2, y1, y2, board) && board[y1][x2] == 0)) {
		return true;
	}
	/*if ((board[y1][0] == 0 &&
		board[y2][0] == 0 &&
		allow(x1, 0, y1, y1, board) &&
		allow(x2, 0, y2, y2, board)) ||
		(board[y1][5] == 0 &&
			board[y2][5] == 0 &&
			allow(x1, 5, y1, y1, board) &&
			allow(x2, 5, y2, y2, board)) ||
		(board[0][x1] == 0 &&
			board[0][x2] == 0 &&
			allow(x1, x1, y1, 0, board) &&
			allow(x2, x2, y2, 0, board)) ||
		(board[5][x1] == 0 &&
			board[5][x2] == 0 &&
			allow(x1, 5, y1, y1, board) &&
			allow(x2, 5, y2, y2, board))) {
		return true;
	}*/

	for (int i = 0; i <8; i ++) {
		if (board[y1][i] == 0 &&
			board[y2][i] == 0 && 
			allow(x1, i, y1, y1, board) &&
			allow(i, i, y1, y2, board) &&
			allow(x2, i, y2, y2, board) ) {
			return true;
		}
	}
	for (int i = 0; i < 8; i ++) {
		if (board[i][x1] == 0 &&
			board[i][x2] == 0 && 
			allow(x1, x1, y1, i, board) &&
			allow(x1,x2,i,i, board) && 
			allow(x2, x2, y2, i, board)
			) {
			return true;
		}
	}

	return false;
}

void main() {
	/*string a, n;
	while (cin >> a)n += " " + a;
	cout << n;
	return;*/
	string pm = "pair matched", bp = "bad pair";
	int board[8][8] = {0};
	for (int i = 0; i < 36; i++) {
		cin >> board[i / 6+1][i % 6+1];
	}
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (tong(x1+1, x2+1, y1+1, y2+1, board)) {
			board[y1+1][x1+1] = 0;
			board[y2+1][x2+1] = 0;
			cout << pm << endl;
		}
		else {
			cout << bp << endl;
		}
		
		/*cout << endl;
		for (int i = 0; i < 36; i++) {
			cout << board[i / 6+1][i % 6+1] << " ";
			if (i % 6 == 5)cout << endl;
		}
		cout << endl;*/
		
	}
}