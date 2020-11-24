#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    double th[] = {0, 0, 1/36.0, 2/36.0, 3/36.0, 4/36.0, 5/36.0, 6/36.0, 5/36.0, 4/36.0, 3/36.0, 2/36.0, 1/36.0};
    srand(time(NULL));
    int count[13]={0};
    int counttable[7][7]={0};
    for(int i=0;i<36000;i++){
        int a = rand()%6+1;
        int b = rand()%6+1; 
        count[a+b]++;
        counttable[a][b]++;
    }
    printf("a\\b\t1\t2\t3\t4\t5\t6\n");
    for(int i=1;i<7;i++){
        printf("%d", i);
        for(int j=1;j<7;j++)printf("%8d", counttable[i][j]);
        printf("\n");
    }

    printf("       sum      time   act_rate theo_rate\n");
    for(int i=2;i<13;i++){
        printf("%10d%10d%10.2lf%10.2lf\n", i, count[i], count[i]/36000.0, th[i]);
    }
}