#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Edge
{
    int weight;
    int n1;
    int n2;
    Edge(int n1_, int n2_, int w) : n1(n1_), n2(n2_), weight(w) {}
    bool operator<(const Edge &b) const
    {
        if (weight < b.weight)
        {
            return true;
        }
        if (weight == b.weight)
        {
            if (n1 < b.n1)
            {
                return true;
            }
            if (n1 == b.n1)
            {
                return n2 < b.n2;
            }
        }
        return false;
    }
    bool operator>(const Edge &b) const
    {
        return b < (*this);
    }
};

int main()
{
    int vc, ec;
    while (cin >> vc >> ec)
    {
        priority_queue<Edge, vector<Edge>, greater<Edge>> graph;
        for (int i = 0; i < ec; i++)
        {
            int n1, n2, w;
            cin >> n1 >> n2 >> w;
            if (n1 > n2)
            {
                int t = n2;
                n2 = n1;
                n1 = t;
            }
            if (n1 != n2)
            {
                graph.push(Edge(n1, n2, w));
            }
        }

        vector<Edge> forest;
        map<int, int> forest_n;
        while (forest.size() < vc - 1)
        {
            Edge e = graph.top();
            if (!forest_n.count(e.n1)||!forest_n.count(e.n2) || forest_n[e.n1] != forest_n[e.n2])
            {
                forest.push_back(e);
                if (forest_n.count(e.n1))
                {
                    if (forest_n.count(e.n2))
                    {
                        int t = forest_n[e.n2];
                        for (auto &i : forest_n)
                        {
                            if (i.second == t)
                                i.second = forest_n[e.n1];
                        }
                    }
                    else
                    {
                        forest_n[e.n2] = forest_n[e.n1];
                    }
                }
                else
                {
                    if (forest_n.count(e.n2))
                    {
                        forest_n[e.n1] = forest_n[e.n2];
                    }
                    else
                    {
                        forest_n[e.n1] = forest.size();
                        forest_n[e.n2] = forest.size();
                    }
                }
            }
            // for (auto &i : forest_n)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            graph.pop();
        }

        sort(forest.begin(), forest.end());
        for (auto &i : forest)
        {
            cout << i.n1 << " " << i.n2 << " " << i.weight << endl;
        }
    }
}