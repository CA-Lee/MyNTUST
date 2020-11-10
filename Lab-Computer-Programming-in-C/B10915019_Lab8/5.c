#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(){
    srand(time(NULL));
    int a=rand()%9+1, b=rand()%9+1;
    printf("How much is %d times %d?", a, b);
    return a*b;
}

int main(){
    while(1){
        int c=0, t=0;
        while(t<10){
            int ans = gen();
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
                    c++;
                    t++;
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
                    t++;
                    break;
                }
            }
        }
        //printf("%lf", ((c+0.0)/t));
        if(((c+0.0)/t)>0.75)puts("Congratulations, you are ready to go to the next level!");
        else puts("Please ask your teacher for extra help.");
    }
}
