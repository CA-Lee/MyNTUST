#include <stdio.h>

int main(){
    printf("Enter the number of lines:");
    int n;
    scanf("%d",&n);
    for(int i = n;i>0;i--){
        for(int j = i;j>1;j--){
            printf("%d ",j);
        }
        printf("1");
        for(int j = 2;j<=i;j++){
            printf("% d",j);
        }
        printf("\n");
    }
    //printf("%d\n",n);
}