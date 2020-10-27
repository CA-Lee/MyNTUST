#include <stdio.h>
#include <math.h>

int det(int a, int b, int c){
    if(a>b&&a>c){
        if(pow(a+0.0,2)==pow(b+0.0,2)+pow(c+0.0,2))return 1;
    }else if(b>a&&b>c){
        if(pow(b+0.0,2)==pow(a+0.0,2)+pow(c+0.0,2))return 1;
    }else if(c>a&&c>b){
        if(pow(c+0.0,2)==pow(b+0.0,2)+pow(a+0.0,2))return 1;
    }
    return 0;
}

int main(){
    int a,b,c;
    printf("enter 3 numbers:");
    scanf("%d %d %d", &a, &b, &c);
    if(det(a,b,c))printf("yes\n");
    else printf("no\n");
}
