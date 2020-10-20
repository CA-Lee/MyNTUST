#include <stdio.h>

int main(){
    int n = 1;
    while((n*n*n)<12000)n++;
    printf("%d\n",n);
}