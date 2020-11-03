#include <stdio.h>

void hanoi(int n, char* s, char* d, char* a){
    if(n==1){
        printf("%s -> %s\n", s, d);
        return;
    }
    hanoi(n-1, s, a, d);
    printf("%s -> %s\n", s, d);
    hanoi(n-1, a, d, s);
}

int main(){
    hanoi(5, "1", "3", "2");
}