#include <stdio.h>

int power(int b, int e){
    if(e==1)return b;
    return b*power(b,e-1);
}

int main(){
    printf("Enter b & e:");
    int b,e;
    scanf("%d %d", &b, &e);
    printf("power: %d\n", power(b,e));
}