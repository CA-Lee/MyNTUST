#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct p {
    int x;
    int y;
    int d;
} P;

typedef struct se {
    P start;
    P end;
} SE;

int mazeTraverse(char maze[][12],P start){
    int x = start.x;
    int y = start.y;
    int d = start.d;
    //printf("x=%d, y=%d, d=%d\n",x,y,d);
    maze[y][x]='x';
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    puts("");
    if(x==11&&d==1){
        return 1;
    }else if(x==0&&d==3){
        return 1;
    }else if(y==0&&d==0){
        return 1;
    }else if(y==11&&d==2){
        return 1;
    }
    switch(d){
        case 0:
            if(maze[y][x+1]=='#'){
                if(maze[y-1][x]=='#')d=3;
            }else d=1;
            break;
        case 1:
            if(maze[y+1][x]=='#'){
                if(maze[y][x+1]=='#')d=0;
            }else d=2;
            break;
        case 2:
            if(maze[y][x-1]=='#'){
                if(maze[y+1][x]=='#')d=1;
            }else d=3;
            break;
        case 3:
            if(maze[y-1][x]=='#'){
                if(maze[y][x-1]=='#')d=2;
            }else d=0;
            break;
    }
    P newP;
    newP.x = x;
    newP.y = y;
    newP.d = d;
    switch(d){
        case 0:
            if(maze[y-1][x]!='#')newP.y--;
            break;
        case 1:
            if(maze[y][x+1]!='#')newP.x++;
            break;
        case 2:
            if(maze[y+1][x]!='#')newP.y++;
            break;
        case 3:
            if(maze[y][x-1]!='#')newP.x--;
            break;
    }
    //printf("newP: x=%d, y=%d, d=%d\n", newP.x,newP.y,newP.d);
    return mazeTraverse(maze,newP);
}

void recursive_gen(char maze[][12], int x, int y){
    //printf("%d,%d\n",x,y);
    if(maze[y*2+1][x*2+1]=='.')return;
    maze[y*2+1][x*2+1]='.';
    int c = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    while(1){
        //puts("while");
        c=0;
        for(int i=0;i<4;i++){
            if(x==0&&i==3)continue;
            if(x==4&&i==1)continue;
            if(y==0&&i==0)continue;
            if(y==4&&i==2)continue;
            if(maze[y*2+1+dy[i]*2][x*2+1+dx[i]*2]=='*')c++;
        }
        //printf("c = %d, ", c);
        if(!c)return;
        int step = rand()%c+1;
        int d = 0;
        for(int i=0;i<step;){
            d=(d+1)&3;
            if(x==0&&d==3)continue;
            if(x==4&&d==1)continue;
            if(y==0&&d==0)continue;
            if(y==4&&d==2)continue;
            if(maze[y*2+1+dy[d]*2][x*2+1+dx[d]*2]=='*')i++;
        }
        //printf("d = %d, ",d);
        maze[y*2+1+dy[d]][x*2+1+dx[d]]='.';
        recursive_gen(maze,x+dx[d],y+dy[d]);
    }
}

SE mazeGenerator(char maze[][12]){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            maze[i][j]='#';
            if(i&1&&j&1&&i!=11&&j!=11)maze[i][j]='*';
            if(i==10&&j&1&&j!=11)maze[i][j]='.';
            if(j==10&&i&1&&i!=11)maze[i][j]='.';
        }
    }
    SE r;
    int n = (rand()%5)*2+1;
    if(rand()&1){
        r.start.x = n;
        if(rand()&1){
            maze[0][n]='.';
            r.start.y = 0;
            r.start.d = 2;
            r.end.x = (rand()%5)*2+1;
            r.end.y = 11;
            r.end.d = 0;
            maze[11][r.end.x]='.';
            maze[10][r.end.x]='.';    
        }else{
            maze[11][n]='.';
            maze[10][n]='.';
            r.start.y = 11;
            r.start.d = 0;
            r.end.x = (rand()%5)*2+1;
            r.end.y = 0;
            r.end.d = 2;
            maze[0][r.end.x]='.';
        }
    }else{
        r.start.y = n;
        if(rand()&1){
            maze[n][0]='.';
            r.start.x = 0;
            r.start.d = 1;
            r.end.x = 11;
            r.end.y = (rand()%5)*2+1;;
            r.end.d = 0;
            maze[r.end.y][11]='.';
            maze[r.end.y][10]='.'; 
        }else{
            maze[n][11]='.';
            maze[n][10]='.';
            r.start.x = 11;
            r.start.d = 3;
            r.end.x = 0;
            r.end.y = (rand()%5)*2+1;
            r.end.d = 0;
            maze[r.end.y][0]='.';
        }
    }
    recursive_gen(maze, rand()%5, rand()%5);
    return r;
}

int main(){
    srand(time(NULL));
    char maze[12][12];
    SE startnend = mazeGenerator(maze);
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    mazeTraverse(maze, startnend.start);
}