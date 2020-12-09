#include <stdio.h>
#include <string.h>

void rep(){
    char *t = strtok(NULL," ");
    if(t==NULL)return;
    rep();
    printf("%s ",t);
}

int main()
{
    char s[9999];
    scanf("%[^\n]",s);
    char *t = strtok(s," ");
    rep();
    printf("%s\n",t);
}