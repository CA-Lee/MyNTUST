#include <stdio.h>
#include <string.h>

int main()
{
    char s[9999];
    scanf("%s", s);
    char *locs = strtok(&s[1], ")");
    int loci = (locs[0] - '0') * 10 + (locs[1] - '0');
    printf("%02d\n", loci);
    char *f4s = strtok(&s[4], "-");
    long num = 0;
    for(int i=0;i<4;i++){
        num*=10;
        num += f4s[i]-'0';
    }
    char *l4s = strtok(&s[9],"");
    for(int i=0;i<4;i++){
        num*=10;
        num += l4s[i]-'0';
    }
    printf("%08ld\n",num);
    puts("");
}