#include <stdio.h>

int isEven(int n){
    return !(n%2);
}

int main(){
    while(1){
        int n;
        scanf("%d", &n);
        if(!n)break;
        if(isEven(n)){
            printf("%d is even\n",n);
        }else{
            printf("%d is odd\n",n);
        }
    }
}
