#include <stdio.h>
#include <string.h>

int main(){
    char ss[6][100];
    for(int i =0;i<6;i++){
        scanf("%s",ss[i]);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(strcmp(ss[j],ss[j+1])>0){
                //puts("swap");
                char temp[100];
                memmove(temp,ss[j+1],100);
                memmove(ss[j+1],ss[j],100);
                memmove(ss[j],temp,100);
            }
        }
    }
    for(int i =0;i<6;i++){
        printf("\"%s\", ",ss[i]);
    }
}