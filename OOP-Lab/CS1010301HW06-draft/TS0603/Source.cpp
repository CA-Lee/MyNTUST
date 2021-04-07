#include "NumberGame.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

void NumberGame::SetInput(int i) {
    a = i;
}
void NumberGame::ProcessInput() {
    alist = vector<int>{};
    string n = to_string(a);
    for (int i = 0; i < pow(2, n.size()); i++) {
        int k = 1;
        for (int j = 0; j < n.size(); j++) {
            k *= ((i >> j) & 1) ? n[j]-'0' : 1;
        }

        int flag = 0;
        for (auto& j : alist) {
            if (j == k) {
                flag++;
                break;
            }
        }
        if(!flag)alist.push_back(k);
    }
}
void NumberGame::SetFileName(string fname) {
    filename = fname;
}
void NumberGame::LoadNumberList() {
    ifstream f{ filename };
    s = vector<int>{ {0} };
    while (f>>s[s.size()-1])
    {
        s.push_back(0);
    }
    sort(s.begin(), s.end());
}
void NumberGame::PrintAllValid() {
    for (auto& i : s) {
        if (i == 0)continue;
        if (i == 1) {
            for (auto& j : to_string(a)) {
                if (i == j-'0') {
                    cout << i << endl;
                    break;
                }
            }
        }
        else {
            for (auto& j : alist) {
                if (i == j) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}
void NumberGame::Reset() {}
