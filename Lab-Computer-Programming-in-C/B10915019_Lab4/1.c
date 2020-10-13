#include <stdio.h>

void p(){
    printf("%s","*");
}
void s(){
    printf("%s"," ");
}
void n(){
    printf("%s","\n");
}

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<=i;j++)p();
        n();
    }
    n();
    for(int i=9;i>=0;i--){
        for(int j=0;j<=i;j++)p();
        n();
    }
    n();
    for(int i=0;i<10;i++){
        for(int j=9;j>i;j--)s();
        for(int j=0;j<=i;j++)p();
        n();
    }
    n();
    for(int i=9;i>=0;i--){
        for(int j=9;j>i;j--)s();
        for(int j=0;j<=i;j++)p();
        n();
    }
    n();
}