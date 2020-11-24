#include <stdio.h>

int main(){
    int canvas[50][50]={0};
    int pen = 0;
    int x = 0;
    int y = 0;
    int d = 1; // urdl
    while(1){
        char str[5];
        scanf("%s",str);
        //printf("%s", str);
        if(str[0]=='9')break;
        else if(str[0]=='1')pen = 0;
        else if(str[0]=='2')pen = 1;
        else if(str[0]=='3')d = (d+1) & 3;
        else if(str[0]=='4')d = (d-1) & 3;
        else if(str[0]=='5'){
            int step;
            if(str[3] != '\0')step=(str[2]-'0')*10+(str[3]-'0');
            else step=str[2]-'0';
            for(int i=0;i<step;i++){
                if(pen)canvas[y][x]=1;
                switch(d){
                    case 0:
                        if(y)y--;
                        break;
                    case 1:
                        if(x<49)x++;
                        break;
                    case 2:
                        if(y<49)y++;
                        break;
                    case 3:
                        if(x)x--;
                        break;
                }
            }
        }
        else if(str[0]=='6'){
            for(int i=0;i<50;i++){
                for(int j=0;j<50;j++)printf(canvas[i][j]?" *":"  ");
                printf("\n");
            }
        }
    }
}