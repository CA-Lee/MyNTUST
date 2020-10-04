#include <stdio.h>

int main(){
    int a;
    int b;
    printf("Please enter the first number:");
    scanf("%d",&a);
    printf("Please enter the second number:");
    scanf("%d",&b);
    printf("first number is");
    printf( (a%b) ? " not" : "");
    printf(" the second's multiple.\n");
}