#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        char s[9999];
        char *ss = s;
        size_t size = 9999;
        getline(&ss,&size,stdin);
        //fflush(stdin);
        //puts("read");
        //printf("echo:%s\n", s);
        char *t = strtok(s, " ");

        while (t != NULL)
        {
            count++;
            t = strtok(NULL, " ");
        }
    }
    printf("%d", count);
    puts("");
}