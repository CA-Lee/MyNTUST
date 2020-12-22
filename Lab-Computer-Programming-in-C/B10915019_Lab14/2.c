#include <stdio.h>

struct four_c
{
    char a;
    char b;
    char c;
    char d;
};

union magic
{
    unsigned int ui;
    struct four_c fc;
};

union magic packCharacters(char a, char b)
{
    union magic ret;
    ret.ui = 0;
    ret.fc.b = a;
    ret.fc.a = b;
    return ret;
}

int main(){
    char str[3];
    puts("combine char");
    scanf("%2s",str);
    for(int i=7;i>-1;i--){
        printf("%d", (str[0]>>i)&1);
    }
    puts("");
    for(int i=7;i>-1;i--){
        printf("%d", (str[1]>>i)&1);
    }
    puts("");
    union magic res = packCharacters(str[0],str[1]);
    for(int i=31;i>-1;i--){
        printf("%d", (res.ui>>i)&1);
    }
    puts("");
    
}