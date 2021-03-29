#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<vector<int>> board;
		for (int i = 0; i < 9;i++) {
			board.push_back(vector<int>());
			for (int j = 0; j < 8;j++) {
					char a;
				if (!i&&! j) {
					board[i].push_back(n);
					cin >> a;
				}
				else {
					board[i].push_back(0);
					cin >> board[i][j];
					cin >> a;
				}
			}
			board[i].push_back(0);
			cin >> board[i][8];
		}

		//check row
		for (auto& i : board) {
			int sum=0;
			for (auto& j : i) {
				sum += 1<<(j-1);
			}
			if (sum != 511) {
				goto fal;
			}
		}
		//check col
		for (int j = 0; j < 9; j++) {
			int sum = 0;
			for (int i = 0; i < 9;i++) {
				sum +=1<<(board[i][j]-1);
			}
			if (sum != 511) {
				goto fal;
			}
		}
		//check blocks
		for (int my = 0; my < 9; my+=3) {
			for (int mx = 0; mx < 9; mx+=3) {
				int sum = 0;
				for (int i = my ; i < my  + 3; i++) {
					for (int j = mx ; j < mx+ 3; j++) {
						sum += 1<<(board[i][j]-1);
					}
				}
				if (sum != 511) {
					goto fal;
				}
			}
		}

		cout << "True" << endl;
		continue;

	fal:
		cout << "False" << endl;
	}
}