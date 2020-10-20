#include <stdio.h>
#include <math.h>

int main(){
    double sum=0;
    for(int i = 1;i<1000;i++){
        sum += 1.0/(sqrt(i)+sqrt(i+1));
    }
    printf("%lf\n",sum);
}