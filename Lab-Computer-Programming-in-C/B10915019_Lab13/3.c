#include <stdio.h>

typedef struct fraction {
    int numerator ;
    int denominator ;
}fraction;

void reduce(struct fraction f, struct fraction * reduced_f){
    int gcd = f.numerator;
    while(f.numerator%gcd||f.denominator%gcd)gcd--;
    reduced_f->numerator = f.numerator/gcd;
    reduced_f->denominator  =f.denominator/gcd;
}

int main(){
    printf("Enter a fraction:");
    struct fraction i,o;
    scanf("%d/%d",&i.numerator,&i.denominator);
    reduce(i,&o);
    printf("In lowest terms: %d/%d\n",o.numerator,o.denominator);

}