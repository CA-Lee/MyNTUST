#include <stdio.h>

void reverseBits(unsigned int in){
    for(int i=0;i<32;i++){
        printf("%d", in&1);
        in >>= 1;
    }
    puts("");
}

int main(){
    puts("reversebit");
    unsigned int n;
    scanf("%u",&n);
    for(int i=31;i>-1;i--){
        printf("%d", (n>>i)&1);
    }
    puts("");
    reverseBits(n);
}