#include <iostream>

using namespace std;

bool ok(int a,int b,int map[], int is_oasis[] , int n, int w){
    if(a==b)return true;
    if(is_oasis[a])w=2;
    
    for(int i=0;i<n;i++){
        if((w&&map[a*n+i])||(is_oasis[i]&&map[a*n+i])){
            if(ok(i,b,map,is_oasis,n,w-1))return true;
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int is_oasis[n];
    int is_oasis2[n];
    int map[n][n];
    for (int i = 0; i < n; i++)
    {
        cin >> is_oasis[i];
        is_oasis2[i] = is_oasis[i];
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
        map[a][b] = 1;
        map[b][a] = 1;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (is_oasis[i])
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (map[i][j])
    //                 is_oasis2[j] = 1;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (is_oasis2[i])
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (is_oasis2[j])
    //             {
    //                 for (int k = 0; k < n; k++)
    //                 {
    //                     if ((i != j && map[j][i]) && (i != k && map[i][k]) && is_oasis2[k])
    //                     {
    //                         map[j][k] = 1;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    int a, b;
    while (cin >> a >> b)
    {
        bool f = ok(a,b,(int*)map,is_oasis,n,1);
        // if (map[a][b])
        // {
        //     f = true;
        // }
        // else
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (is_oasis2[i] && map[a][i])
        //         {
        //             for (int j = 0; j < n; j++)
        //             {
        //                 if (is_oasis2[j] && map[j][b])
        //                 {
        //                     f = true;
        //                 }
        //             }
        //         }
        //     }
        // }
        cout << (f ? "Yes" : "No") << endl;
    }
}