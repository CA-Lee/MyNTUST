#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(){
    srand(time(NULL));
    int a=rand()%9+1, b=rand()%9+1;
    printf("How much is %d times %d?", a, b);
    return a*b;
}

int main(){
    while(1){
        int ans = gen();
        while(1){
            int in;
            scanf("%d", &in);
            if(in==ans){
                puts("Very good!");
                break;
            }else{
                puts("No, Please try again.");
            }
        }
    }
}
