#include <stdio.h>

int reverse(int n){
    int r=0;
    while(n){
        r*=10;
        r+=n%10;
        n/=10;
    }
    return r;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", reverse(n));
}
