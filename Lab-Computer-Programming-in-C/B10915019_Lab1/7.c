#include <stdio.h>

int main(){
    double m,i,f;
    printf("Enter the amount of water in kilograms:"); //55.5
    scanf("%lf", &m);
    printf("Enter the initial temperature:"); //3.5
    scanf("%lf", &i);
    printf("Enter the final temperature:"); //10.5
    scanf("%lf", &f);
    printf("The energy needed is %.1f\n", (f-i)*m*4184.0);
}