#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int fy,int fx,int ty,int tx,int deck[][13],int book[][13]){
    book[ty][tx]=1;
    int temp = deck[fy][fx];
    deck[fy][fx] = deck[ty][tx];
    deck[ty][tx] = temp;
}

void shuffle(int deck[][13]){
    int book[4][13] = {0};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(book[i][j])continue;
            swap(i,j,rand()&3,rand()%13,deck,book);
        }
    }
}

int main(){
    srand(time(NULL));
    int deck[4][13];
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            deck[i][j]=i*13+j+1;
            //printf("%2d ", deck[i][j]);
        }
        //printf("\n");
    }
    shuffle(deck);
    shuffle(deck);
    shuffle(deck);
    printf("   ");
    for(int i=0;i<13;i++)printf("%2d ",i+1);
    printf("\n");
    for(int i=0;i<4;i++){
        printf("%2d ", i);
        for(int j=0;j<13;j++){
            printf("%2d ", deck[i][j]);
        }
        printf("\n");
    }
}