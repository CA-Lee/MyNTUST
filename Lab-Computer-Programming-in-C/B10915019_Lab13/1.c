#include <stdio.h>

int fact_calc(int n,char* str){
    if(!n){
        sprintf(str,"0!=1");
        return 4;    
    }
    char* head = str;
    sprintf(str,"%d!=%d",n,n);
    str += 4;
    int s = n;
    for(int i=n-1;i>0;i--){
        sprintf(str,"x%d",i);
        str += 2;
        s*=i;
    }
    sprintf(str,"=%d",s);
    int c = 0;
    while(head[c]!='\0')c++;
    return c;
}

int main(){
    while(1){
        printf("Enter an integer between 0 and 9 or -1 to quit: ");
        int in;
        scanf("%d",&in);
        if(in==-1)break;
        if(in>9||in<0){
            puts("Invalid entry");
            continue;
        }
        char str[10000];
        int len = fact_calc(in, str);
        for(int i=0;i<(len+2);i++)printf("*");
        printf("\n*");
        printf("%s",str);
        printf("*\n");
        for(int i=0;i<(len+2);i++)printf("*");
        puts("");
    }
}