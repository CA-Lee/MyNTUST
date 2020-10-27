#include <stdio.h>
#include <math.h>

double ntsqrt(double n){
    double y = 1;
    double oldy = 0;
    while(fabs(y-oldy)>(0.00001*y)){
        oldy = y;
        y = (y+(n/y))/2.0;
    }
    return y;
}

int main(){
    printf("Enter a positive number:");
    double n;
    scanf("%lf", &n);
    printf("Square root: %lf\n", ntsqrt(n));
}
