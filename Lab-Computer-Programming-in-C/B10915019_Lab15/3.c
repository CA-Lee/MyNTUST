#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tran
{
    char name[50];
    double amount;
    struct tran *next;
}tran;
    
int main(){
    char *old = "oldmast.txt";
    char *trans = "trans.txt";
    char *new = "newmast.txt";

    FILE* fold = fopen(old,"r");
    tran* ptr = malloc(sizeof(tran));
    ptr->next = NULL;
    tran* balances = ptr;
    while(fscanf(fold,"%s %lf",(char*)&ptr->name,&ptr->amount)!=EOF){
        ptr->next = malloc(sizeof(tran));
        ptr = ptr->next;
        ptr->next = NULL;
    }

    puts("\noldmast.txt");
    ptr = balances;
    while (ptr->next!=NULL)
    {
        printf("%s %lf\n",ptr->name,ptr->amount);
        ptr = ptr->next;
    }    

    tran input;
    FILE* ftran = fopen(trans,"w");
    while (scanf("%s %lf",(char*)&input.name,&input.amount)!=EOF)
    {
        fprintf(ftran,"%s %lf\n",input.name,input.amount);
    }
    fclose(ftran);

    puts("\nprocessing...");
    ftran = fopen(trans,"r");
    FILE* fnew = fopen(new,"w+");
    tran now;
    while (fscanf(ftran,"%s %lf",(char*)&now.name,&now.amount)!=EOF)
    {
        ptr = balances;
        int exist = 0;
        while (ptr->next!=NULL)
        {   
            if(!strcmp(now.name,ptr->name)){
                ptr->amount += now.amount;
                exist = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(exist == 0){
            printf("Unmatched transaction record for account number %s\n",now.name);
            while (ptr->next!=NULL)ptr = ptr->next;
            strcpy(ptr->name, now.name);
            ptr->amount = now.amount;
            ptr->next = malloc(sizeof(tran));
            ptr = ptr->next;
            ptr->next = NULL;
        }
    }

    puts("\nnewmast.txt");
    ptr = balances;
    while (ptr->next!=NULL)
    {
        printf("%s %lf\n",ptr->name,ptr->amount);
        fprintf(fnew,"%s %lf\n",ptr->name,ptr->amount);
        ptr = ptr->next;
    }

    fclose(fnew);
    fclose(fold);
    fclose(ftran);
}