#include <stdio.h>

int testPalindrome(char s[], int l)
{
    if (l == 0)
        return 1;
    if (l == 1)
    {
        if (s[0] == s[1])
            return 1;
        if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')))
        {
            return 1;
        }
        if (!((s[1] >= 'a' && s[1] <= 'z') || (s[1] >= 'A' && s[1] <= 'Z')))
        {
            return 1;
        }
        return 0;
    }
    int i = 0;
    while (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))i++;
    while (!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z')))l--;
    
    if(s[i]==s[l]){
        return testPalindrome(&s[i+1], l-1-i-1);
    }else return 0;
}

int main()
{
    char s[9999];
    scanf("%[^\n]", s);
    int i = 0;
    while (s[i+1] != '\0')
        i++;
    if (testPalindrome(s, i))
    {
        puts("yes");
    }
    else
        puts("no");
}