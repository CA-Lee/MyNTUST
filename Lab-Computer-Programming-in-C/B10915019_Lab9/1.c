#include <stdio.h>

int main(){
    int a1[5],a2[5];
    for(int i=0;i<5;i++)scanf("%d",&a1[i]);
    for(int i=0;i<5;i++)scanf("%d",&a2[i]);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a1[i]==a2[j]){
                printf("%d ",a1[i]);
                break;
            }
        }
    }
    puts("");
}