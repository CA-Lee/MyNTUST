#include <stdio.h>

int main(){
    int a,b,c;
    printf("Enter three different integers:"); //13  27  14
    scanf("%d %d %d", &a, &b, &c);
    printf("Sum is %d.\n", (a+b+c) ); // 54
    printf("Average is %lf.\n", (double)(a+b+c)/3.0 ); // 18
    printf("Product is %d.\n", (a*b*c) ); // 4914
    printf("Smallest is "); // 13
    if(a<b && a<c){
        printf("%d\n", a);
    }else if(b<a && b<c){
        printf("%d\n", b);
    }else if(c<a && c<b){
        printf("%d\n", c);
    }
    printf("Largest is "); // 27
    if(a>b && a>c){
        printf("%d\n", a);
    }else if(b>a && b>c){
        printf("%d\n", b);
    }else if(c>a && c>b){
        printf("%d\n", c);
    }
}