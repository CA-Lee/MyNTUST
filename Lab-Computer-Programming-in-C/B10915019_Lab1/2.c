#include <stdio.h>

int main(){
    int in;
    printf("Please enter time elapsed in second:");
    scanf("%d", &in);
    int m,s;
    s = in % 60;
    in /= 60;
    m = in % 60;
    in /= 60;
    printf("%d:%d:%d\n", in, m, s);
}