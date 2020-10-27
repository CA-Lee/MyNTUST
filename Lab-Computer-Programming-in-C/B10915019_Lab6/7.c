#include <stdio.h>

void isPerfect(int n){
    int a = 0;
    for(int i = 1;i<n;i++){
        if(n%i==0){
            a+=i;
        }
    }
    if(a==n){
        printf("%d: ", n);
        for(int i = 1;i<n;i++){
            if(n%i==0){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}

int main(){
    for(int i =1;i<1001;i++){
        isPerfect(i);
    }
}
