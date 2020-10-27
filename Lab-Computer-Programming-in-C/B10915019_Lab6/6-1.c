#include <stdio.h>
#include <math.h>

double ntsqrt(double n, double y){
    //printf("%lf",y);
    if(fabs(y-(n/y+y)/2)<=0.00001*y)return y;
    else{
        y = ((n/y)+y)/2;
        return ntsqrt(n,y);
    }
}

int main(){
    printf("Enter a positive number:");
    double n;
    scanf("%lf", &n);
    printf("Square root: %lf\n", ntsqrt(n,1));
}
