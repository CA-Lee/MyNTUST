#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {

	int cn;
	while (cin >> cn) {
		map<int,int> timeline;
		for (int i = 0; i < cn; i++) {
			int t, f;
			cin >> t >> f;
			timeline[t] = f;
		}

		int t = 1, f = 1, move = 0;
		set<int> target_list;
		while ( timeline.size() || target_list.size()) {
			cout << t << " " << f << endl;

			if (timeline.find(t) != timeline.end()) {
				target_list.insert(timeline[t]);
				timeline.erase(t);
			}

			if (target_list.find(f) != target_list.end())
				target_list.erase(target_list.find(f));


			if (target_list.size()) {
				if (move == 1 && *target_list.rbegin() < f) {
					move = -1;
				}
				else if (move == -1 && *target_list.begin() > f) {
					move = 1;
				}
				else if (move == 0) {
					if (*target_list.begin() > f)move = 1;
					else if (*target_list.begin() < f)move = -1;
				}
			}
			else {
				move = 0;
			}


			t++;
			f += move;
		}
	}

}