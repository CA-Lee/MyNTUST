#include <iostream>

using namespace std;
int main(){
    int n,m;
    int map[5000030] = {0};
    while (cin >> n)
    {
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            map[k]=i+1;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int k;
            cin >> k;
            cout << map[k]-1 <<endl;
        }
    }
    
}