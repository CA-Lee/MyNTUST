#include <stdio.h>

int main(){
    int n ,i=2, c=0;
    scanf("%d", &n);
    //printf("%d",n%i);
    while(n>1){
      if((n%i)==0){
          if(!c){
              printf("%d",i);
              c++;
          }else printf(", %d",i);
        n /= i;
      }else{
        i++;
      }
    }
    printf("\n");
}