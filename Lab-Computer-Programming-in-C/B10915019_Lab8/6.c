#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(int level){
    srand(time(NULL));
    int a, b;
    switch(level){
        case 1:
            a=rand()%9+1;
            b=rand()%9+1;
            break;
        case 2:
            a=rand()%99+1;
            b=rand()%99+1;
            break;
        case 3:
            a=rand()%999+1;
            b=rand()%999+1;
            break;
    }
    printf("How much is %d times %d?", a, b);
    return a*b;
}

int main(){
    printf("Choose level 1-3:");
    int level;
    scanf("%d", &level);
    while(1){
        int ans = gen(level);
        while(1){
            int in;
            scanf("%d", &in);
            srand(time(NULL));
            if(in==ans){
                switch(rand()%4+1){
                    case 4:
                        puts("Very good!");
                        break;
                    case 1:
                        puts("Excellent!");
                        break;
                    case 2:
                        puts("Nice work!");
                        break;
                    case 3:
                        puts("Keep up the good work!");
                        break;
                }
                break;
            }else{
                switch(rand()%4+1){
                    case 4:
                        puts("No. Please try again.");
                        break;
                    case 1:
                        puts("Wrong. Try once more.");
                        break;
                    case 2:
                        puts("Don’t give up.");
                        break;
                    case 3:
                        puts("No. Keep trying.");
                        break;
                }
            }
        }
    }
}
