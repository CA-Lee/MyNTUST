#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void show(int t,int h){
    for(int i=1; i < (t>h?h:t);i++){
        printf(" ");
    }
    if(t==h&&t)printf("OUCH!!!");
    else{
        printf((t>h?"H":"T"));
        for(int i=(t>h?h:t)+1;i<(t>h?t:h);i++)printf(" ");
        printf((t>h?"T":"H"));
    }
    for(int i=(t>h?t:h);i<80;i++)printf(" ");
    printf("\r");
    fflush(stdout);
}

int main(){
    printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");
    srand(time(NULL));
    for(int h=0,t=0;1;sleep(1)){
        switch(rand()%10){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                t+=3;
                break;
            case 5:
            case 6:
                t-=6;
                if(t<0)t=0;
                break;
            case 7:
            case 8:
            case 9:
                t++;
        }
        switch(rand()%10){
            case 0:
            case 1:
                break;
            case 2:
            case 3:
                h+=9;
                break;
            case 4:
                h-=12;
                if(h<0)h=0;
                break;
            case 5:
            case 6:
            case 7:
                h+=1;
                break;
            case 8:
            case 9:
                h--;
                if(h<0)h=0;
        }
        if(h>=70&&t>=70){
            puts("\nTIE!");
            break;
        }
        if(h>=70){
            puts("\nHARE WINS!!! YAY!!!");
            break;
        }
        if(t>=70){
            puts("\nTORTOISE WINS!!! YAY!!! ");
            break;
        }
        show(t,h);
    }    
}