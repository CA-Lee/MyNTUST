#include <stdio.h>

int main(){
    double d,m,p;
    printf("Enter the driving distance:");
    scanf("%lf", &d);
    printf("Enter miles per gallon:");
    scanf("%lf", &m);
    printf("Enter price per gallon:");
    scanf("%lf", &p);
    printf("The cost of driving is $%.2f.\n", (d/m*p));
}