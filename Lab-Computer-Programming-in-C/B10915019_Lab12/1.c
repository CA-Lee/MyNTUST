#include <stdio.h>

void stringReverse(char s[]){
    char* ptr = s;
    if(*ptr == '\0')return;
    stringReverse(ptr+1);
    printf("%c",*ptr);
}

int main(){
    char s[9999];
    scanf("%s",s);
    stringReverse(s);
    puts("");
}