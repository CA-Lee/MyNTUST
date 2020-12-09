#include <stdio.h>
#include <string.h>

/*char* strstr(char* str, char* tgt){
    int a = 0,b = 0;
    while(str[a]!='\0'){
        if(str[a]==tgt[0]){
            b=0;
            while (str[a]==tgt[b]){
                b++;
                a++;
                if(tgt[b]=='\0')return &str[a+b-1];
                if(str[a]=='\0')return NULL;
            }
        }
        a++;
    }
    return NULL;
}
*/
int main()
{

    char s[1000] = {0}, t[1000] = {0};
    size_t size = 1000;
    char *ss = s;
    char *tt = t;
    getline(&ss, &size, stdin);
    scanf("%s", t);
    char *p = strstr(s, t);
    int n = 0;
    if (p != NULL)
    {
        printf("%s", p);
        n++;
        p = strstr(p + 1, t);
        if (p != NULL)
        {
            printf("%s", p);
            n++;
        }
    }
    printf("found %d\n", n);
}