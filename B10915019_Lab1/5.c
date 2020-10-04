#include <stdio.h>

int main(){
    double a,v;
    printf("v:");
    scanf("%lf", &v);
    printf("a:");
    scanf("%lf", &a);
    printf("length: %.3f\n", (v*v)/(2*a));
}