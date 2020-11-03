#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(){
    return (rand() & 1);
}

int main(){
    srand(time(NULL));
    int head=0, tail=0;
    for(int i=0;i<1000;i++){
        if(flip()){
            head++;
        }else{
            tail++;
        }
    }
    printf("Head: %d\nTail: %d\n", head, tail);
}