#include <stdio.h>

int isPrime(int n, int t){
    if(n==t)return 1;
    if(!(n%t))return 0;
    return isPrime(n, t+1);
}

int main(){
    puts("Enter a number:");
    int n;
    scanf("%d", &n);
    if(isPrime(n, 2))puts("is prime");
    else puts("is not prime");
}