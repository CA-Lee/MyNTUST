#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int craps(){
    int a = rand()%6+1;
    int b = rand()%6+1;
    if((a+b)==7||(a+b)==11){
        return 1;
    }else if((a+b)==12||(a+b)==2||(a+b)==3){
        return 0;
    }else{
        int o = a+b;
        while(1){
            a = rand()%6+1;
            b = rand()%6+1;
            if((a+b)==o)return 1;
            else if((a+b)==7)return 0;
        }
    }
}

int main(){
    int bal = 1000;
    srand(time(NULL));
    while(1){
        printf("balance: %d\nenter wager:", bal);
        int wag;
        scanf("%d", &wag);
        while(wag>bal){
            printf("poor, enter a lower number\nenter wager:");
            scanf("%d", &wag);
        }
        if(craps())bal += wag;
        else bal -= wag;
        if(bal<=0){
            printf("Sorry. You busted!\n");
            return 0;
        }
    }
}