#include <stdio.h>

int main(){
    int in;
    printf("enter a number:");
    scanf("%d", &in);
    printf( (in & 1) ? "it's odd\n" : "it's even\n");
}