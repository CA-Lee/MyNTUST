#include <iostream>

using namespace std;
void find_route(int i, int map[], int mark[], int is_oasis[], int n)
{
    mark[i] = 1;
    for (int j = 0; j < n; j++)
    {

        if (i != j && map[i * n + j] && (is_oasis[i] || is_oasis[j]))
        {
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int is_oasis[n];
    int map[n][n];
    for (int i = 0; i < n; i++)
    {
        cin >> is_oasis[i];
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
            if (i == j)
                map[i][j] = 1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (is_oasis[a] || is_oasis[b])
        {

            map[a][b] = 1;
            map[b][a] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((i != j && map[j][i]) && (i != k && map[i][k]))
                {
                    map[j][k] = 1;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int a, b;
    while (cin >> a >> b)
    {
        cout << (map[a][b] ? "Yes" : "No") << endl;
    }
}