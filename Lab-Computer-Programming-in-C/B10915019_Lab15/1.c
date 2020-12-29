#include <stdio.h>

int main(){
    printf("Enter file name 1:");
    char f1[1000];
    scanf("%s",f1);
    printf("Enter file name 2:");
    char f2[1000];
    scanf("%s",f2);
    char c;
    FILE* fp1 = fopen(f1,"r");
    while((c = fgetc(fp1))!=EOF)putc(c,stdout);
    FILE* fp2 = fopen(f2,"r");
    while((c = fgetc(fp2))!=EOF)putc(c,stdout);
    fclose(fp2);
    fclose(fp1);   
}