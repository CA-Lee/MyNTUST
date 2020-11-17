#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    printf("Enter the number of balls to drop:");// 5
    int bc,sc;
    scanf("%d",&bc);
    printf("Enter the number of slots in the bean machine:"); // 8
    scanf("%d",&sc);
    int slots[sc];
    for(int i=0;i<sc;i++)slots[i]=0;
    for(int i=0;i<bc;i++){
        int pos=0;
        for(int j=1;j<sc;j++){
            if(rand()&1){
                printf("L");
            }else{
                printf("R");
                pos++;
            }
        }
        puts("");
        slots[pos]++;
    }
    int max=slots[0];
    for(int i=1;i<sc;i++)slots[i]>max?max=slots[i]:max;
    for(int i=max;i>0;i--){
        for(int j=0;j<sc;j++){
            if(slots[j]>=i)printf("O");
            else printf(" ");
        }
        puts("");
    }
}