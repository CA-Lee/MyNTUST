#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
while(1){
    printf("I have a number between 1 and 1000\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n");
    srand(time(NULL));
    int ans = rand()%1000+1;
    int in;
    scanf("%d", &in);
    while(in != ans){
        if(in < ans){
            printf("Too low! Try again.\n");
            scanf("%d", &in);
        }else{
            printf("Too high! Try again.\n");
            scanf("%d", &in);
        }
    }
    printf("Excellent! You guessed the number.\n"
            "Would you like to play again (y or n)?");
    char yn[2];
    scanf("%s", yn);
    //printf("%s", yn);
    if(yn[0] != 'y'){
        break;
    }
}
}