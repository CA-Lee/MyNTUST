#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matrix[5][5];
    srand(time(NULL));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            matrix[i][j] = rand() & 1;
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
    int max_row=0,max_col=0,max=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int max_this = 0;
            for(int k=0;k<5;k++){
                max_this+=matrix[i][k];
                max_this+=matrix[k][j];
            }
            max_this-=matrix[i][j];
            if(max_this>max){
                max_row = i;
                max_col = j;
                max = max_this;
            }
        }
    }
    printf("max_row: %d, max_col: %d, max: %d\n", max_row+1, max_col+1, max);
}