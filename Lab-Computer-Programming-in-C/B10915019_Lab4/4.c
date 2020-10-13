#include <stdio.h>
#include <math.h>

void cal(int max){
    double out=0;
    for(int i=1;i<=max;i++){
        out+=4*(pow(-1.0,i+1.0)/(2.0*i-1.0));
    }
    printf("%lf\n",out);
}

int main(){
    for(int i=10000;i<=100000;i+=10000)cal(i);
}