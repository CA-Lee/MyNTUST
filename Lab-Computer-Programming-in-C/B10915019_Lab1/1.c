#include <stdio.h>

int main(){
    int a;
    int b;
    printf("Please enter the first number:");
    scanf("%d",&a);
    printf("Please enter the second number:");
    scanf("%d",&b);
    printf("The sum, product, difference, quotient and remainder are:"
        "%d, %d, %d, %d, %d\n", a+b, a*b, a-b, a/b, a%b);
}