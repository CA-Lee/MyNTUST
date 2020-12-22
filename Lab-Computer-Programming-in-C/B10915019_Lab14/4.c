#include <stdio.h>

int main()
{
    puts("barcode");
    int s = 0;
    for (int i = 0; i < 11; i++)
    {
        int n;
        scanf("%d", &n);
        s += i & 1 ? n : n * 3;
    }
    int c;
    scanf("%d",&c);
    if(c==(10-(s%10))%10)puts("validated.");
    else puts("error in barcode.");

}
