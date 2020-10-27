#include <stdio.h>
#include <math.h>

int main(){
    for(int p=2;p<=31;p++){
        int n = pow(2.0,p+0.0)-1;
        int f = 1;
        double s = sqrt(n);
        for(int i=2;i<s;i++){
            if(n%i==0){
                f=0;
                break;
            }
        }
        if(f){
            printf("%d %d\n", p, n);
        }
    }
}
