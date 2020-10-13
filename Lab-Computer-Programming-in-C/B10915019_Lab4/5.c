#include <stdio.h>

int main(){
    int str[10];
    long in;
    int len=0;
    scanf("%ld",&in);
    while(in){
        str[len]=in%10;
        in/=10;
        len++;
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len-1;j++){
            if(str[j]>str[j+1]){
                int temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }        
    }
    for(int i=0;i<len;i++)printf("%d\n",str[i]);
}