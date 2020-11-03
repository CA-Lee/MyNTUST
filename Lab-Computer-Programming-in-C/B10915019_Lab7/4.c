#include <stdio.h>

int lcm(int b, int e){
    int lcm = b>e?b:e;
    while(lcm%b || lcm%e){
        lcm++;
    }
    return lcm;
}

int main(){
    printf("Enter two int:");
    int b,e;
    scanf("%d %d", &b, &e);
    printf("LCM: %d\n", lcm(b,e));
}