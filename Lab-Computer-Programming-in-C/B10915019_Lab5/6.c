#include <stdio.h>

int main(){
    printf("Enter numbers:");
    int n, max, count = 0;
    scanf("%d",&n);
    max = n;
    count++;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        if(n>max){
            count = 1;
            max = n;
        }else if(n==max){
            count++;
        }
    }
    printf("The largest number is %d\n"
            "The occurrence count of the largest number is %d\n", max, count);
}