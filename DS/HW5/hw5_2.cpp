#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second < b.second)
    {
        return true;
    }
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return false;
}

int main()
{
    int vc, ec;
    while (cin >> vc >> ec)
    {
        map<int, map<int, int>> graph;
        for (int i = 0; i < ec; i++)
        {
            int n1, n2, w;
            cin >> n1 >> n2 >> w;
            graph[n1][n2] = w;
        }
        int start;
        cin >> start;

        map<int, int> dist;
        set<int> ved;

        ved.insert(start);
        dist[start] = 0;
        while (ved.size() < vc)
        {
            for (auto &v : ved)
            {
                for (auto &to : graph[v])
                {
                    if (dist.count(to.first) && dist[to.first] >( dist[v] + to.second))
                    {
                        dist[to.first] = dist[v] + to.second;
                    }
                    else if(!dist.count(to.first))
                    {
                        dist[to.first] = dist[v] + to.second;
                    }
                }
            }
            int nearest = -1;
            for (auto &i : dist)
            {
                // cout << i.first <<":"<<i.second<<", ";
                if (!ved.count(i.first))
                {
                    if (nearest == -1)
                    {
                        nearest = i.first;
                    }
                    else if (dist[nearest] > i.second)
                    {
                        nearest = i.first;
                    }
                }
            }
            // cout<<endl;
            if(nearest==-1)break;
            ved.insert(nearest);
            // cout << nearest <<endl;
        }

        vector<pair<int, int>> out(dist.begin(), dist.end());
        sort(out.begin(), out.end(), comp);
        for (auto &i : out)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
}