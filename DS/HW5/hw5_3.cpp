#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int pc;
    cin >> pc;
    unordered_set<int> ptable;
    vector<int> ps;
    for (int i = 0; i < pc; i++)
    {
        int pn;
        cin >> pn;
        ps.push_back(pn);
        ptable.insert(pn);
    }

    int lucky;
    while (cin >> lucky)
    {
        for (auto &i : ps)
        {
            if (ptable.count(lucky - i))
            {
                cout << i << " " << lucky - i << endl;
                break;
            }
        }
    }
}