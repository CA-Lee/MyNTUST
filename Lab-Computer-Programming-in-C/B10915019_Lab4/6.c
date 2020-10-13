#include <stdio.h>
#include <math.h>

int main(){
    for(int i=1;i<501;i++){
        for(int j=i;j<501;j++){
            for(int k=1;k<501;k++){
                if(pow((double)k,2.0)==(pow((double)i,2.0)+pow((double)j,2.0)))printf("%d %d %d\n", i, j, k);
            }
        }
    }
}