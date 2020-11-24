#include <stdio.h>

int main(){
    int board[3][3]={0};
    while(1){
        int xx,xy;
        do{
        printf("Enter a row (0, 1, or 2) for player X:");
        scanf("%d", &xy);
        printf("Enter a column (0, 1, or 2) for player X:");
        scanf("%d", &xx);
        }while(board[xy][xx]!=0);
        board[xy][xx]=1;
        for(int i=0;i<3;i++){
            puts("-------");
            printf("|");
            for(int j=0;j<3;j++){
                if(board[i][j]==1)printf("X|");
                else if(board[i][j]==2)printf("O|");
                else printf(" |");
            }
            printf("\n");
        }
        puts("-------");
        for(int i=0;i<3;i++){
            if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[i][0])){
                if(board[i][0]==1)printf("X player won.\n");
                else printf("O player won.\n");
                return 0;
            }
            if((board[0][i]==board[1][i])&&(board[1][i]==board[2][i])&&(board[0][i])){
                if(board[0][i]==1)printf("X player won.\n");
                else printf("O player won.\n");
                return 0;
            }
        }
        if(((board[0][0])&&(board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))
        ||((board[0][2])&&(board[0][2]==board[1][1])&&(board[1][1]==board[2][0]))){
            if(board[1][1]==1)printf("X player won.\n");
            else printf("O player won.\n");
            return 0;
        }
        int flag=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0)flag=1;
            }
        }
        if(flag==0){
            printf("draw.\n");
            return 0;
        }
        int yx,yy;
        do{
        printf("Enter a row (0, 1, or 2) for player O:");
        scanf("%d", &yy);
        printf("Enter a column (0, 1, or 2) for player O:");
        scanf("%d", &yx);
        }while(board[yy][yx]!=0);
        board[yy][yx]=2;
        for(int i=0;i<3;i++){
            puts("-------");
            printf("|");
            for(int j=0;j<3;j++){
                if(board[i][j]==1)printf("X|");
                else if(board[i][j]==2)printf("O|");
                else printf(" |");
            }
            printf("\n");
        }
        puts("-------");

        for(int i=0;i<3;i++){
            if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[i][0])){
                if(board[i][0]==1)printf("X player won.\n");
                else printf("O player won.\n");
                return 0;
            }
            if((board[0][i]==board[1][i])&&(board[1][i]==board[2][i])&&(board[0][i])){
                if(board[0][i]==1)printf("X player won.\n");
                else printf("O player won.\n");
                return 0;
            }
        }
        if(((board[0][0])&&(board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))
        ||((board[0][2])&&(board[0][2]==board[1][1])&&(board[1][1]==board[2][0]))){
            if(board[1][1]==1)printf("X player won.\n");
            else printf("O player won.\n");
            return 0;
        }
        flag=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0)flag=1;
            }
        }
        if(flag==0){
            printf("draw.\n");
            return 0;
        }
    }
}