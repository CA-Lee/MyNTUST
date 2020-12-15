#include <stdio.h>
#include <stdlib.h>

typedef struct c {
    double r;
    double i;
}c;

c add_complex(c c1,c c2){
    c r = {.r=c1.r+c2.r,.i=c1.i+c2.i};
    return r;
}

int main(){
    printf("Enter two complex number:");
    char c1[100],c2[100];
    scanf("%s%s",c1,c2);

    c cc1,cc2;
    char* n;
    cc1.r = (double)strtof(c1,&n);
    cc1.i = strtof(n,NULL);
    cc2.r = (double)strtof(c2,&n);
    cc2.i = strtof(n,NULL);
    c res = add_complex(cc1,cc2);
    printf("The sum is %.1lf+%.1lfi\n",res.r,res.i);
}