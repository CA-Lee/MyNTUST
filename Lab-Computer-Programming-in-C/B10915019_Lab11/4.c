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

int rank(int hand[]){
    int icon[5];
    int num[13]={0};
    for(int i=0;i<5;i++){
        icon[i]=(hand[i]-1)/13;
        num[(hand[i]-1)%13]++;
    }
    int flush = 1;
    for(int i=0;i<4;i++){
        if(icon[i]!=icon[i+1])flush=0;      
    }
    int straight = 1;
    int index = 0;
    while(!num[index])index++;
    for(int i=0;i<5;i++){
        if(num[index+i]!=1)straight=0;
    }
    if(straight&&flush){
        puts("straight flush");
        return 1;
    }
    int max = num[0];
    int have_two = 0;
    for(int i=0;i<13;i++){
        if(num[i]>max)max=num[i];
        if(num[i]==2)have_two++;
    }
    if(max==4){
        puts("four of a kind");
        return 2;
    }
    if(max==3&&have_two){
        puts("full house");
        return 3;
    }
    if(flush){
        puts("flush");
        return 4;
    }
    if(straight){
        puts("straight");
        return 5;
    }
    if(max==3){
        puts("three of a kind");
        return 6;
    }
    if(have_two==2){
        puts("two pair");
        return 7;
    }
    if(have_two){
        puts("one pair");
        return 8;
    }
    puts("high card");
    return 9;
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
    int handa[5] = {deck[0][0],deck[0][1],deck[0][2],deck[0][3],deck[0][4]};
    puts("A:");
    for(int i=0;i<5;i++)printf("%d-%d ",(handa[i]-1)/13,(handa[i]-1)%13+1);
    puts("");
    int ra = rank(handa);
    int handb[5] = {deck[1][0],deck[1][1],deck[1][2],deck[1][3],deck[1][4]};
    puts("B:");
    for(int i=0;i<5;i++)printf("%d-%d ",(handb[i]-1)/13,(handb[i]-1)%13+1);
    puts("");
    int rb = rank(handb);
    if(ra>rb){
        puts("B win");
    }else if(ra<rb){
        puts("A win");
    }else puts("draw");
}