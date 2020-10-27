#include <stdio.h>
#include <math.h>

void chk(double a,double b, double c){
    if((b*b-4*a*c)>=0){
        printf("has real root!\n");
        double rootp = (-b+(sqrt(b*b-4*a*c)))/(2*a);
        double rootn = (-b-(sqrt(b*b-4*a*c)))/(2*a);
        printf("root: %lf, %lf\n", rootp, rootn);
    }else{
        printf("has imaginary/complex root!\n");
        double rootr = (-b)/(2*a);
        double rooti = sqrt(-(b*b-4*a*c))/(2*a);
        printf("root: %lf +/- %lfi\n", rootr, rooti);
    }
    
}

int main(){
    printf("enter coefficients:");
    double a,b,c;
    scanf("%lf %lf %lf", &a,&b,&c);
    chk(a,b,c);
}
