#include <stdio.h>

long C(long n, long p){
    if(p==0||p==n)return 1;
    return C(n-1,p)+C(n-1,p-1);
}

int main(){
    puts("Enter n, p:");
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%ld\n", C(n,p));
}