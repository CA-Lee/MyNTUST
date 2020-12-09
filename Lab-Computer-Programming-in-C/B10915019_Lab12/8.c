#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    char *article[] = {"the", "a", "one", "some", "any"},
         *noun[] = {"boy", "girl", "dog", "town", "car"},
         *verb[] = {"drove", "jumped", "ran", "walked", "skipped"},
         *prepositions[] = {"to", "from", "over", "under", "on"};
    for(int i=0;i<20;i++){
        char s[10];
        memmove(s,article[rand()%5],10);
        s[0]+=('A'-'a');
        printf("%s ",s);
        printf("%s ",noun[rand()%5]);
        printf("%s ",verb[rand()%5]);
        printf("%s ",prepositions[rand()%5]);
        printf("%s ",article[rand()%5]);
        printf("%s.\n",noun[rand()%5]);
    }
}