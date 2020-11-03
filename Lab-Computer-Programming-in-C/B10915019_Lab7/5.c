#include <stdio.h>

unsigned long long fib(unsigned int in){
    if(in==1)return 0;
    unsigned long long a=0,b=1;
    for(unsigned int i=2;i<in;i++){
        unsigned long long next = b+a;
        a=b;
        b=next;
    }
    return b;
}

int main(){
    unsigned int i = 2;
    unsigned long long pre = fib(1);
    while(fib(i)>=pre){
        //printf("%llu\n", fib(i));
        pre = fib(i);
        i++;
    }
    printf("%llu\n", pre);
    
}