#include <stdio.h>

int main(void) {
  printf("input:");
  int i;
  scanf("%d",&i);
  if((i%10)==(i/10000) && ((i%100)/10)==((i/1000)%10)){
    printf("yes\n");

  }else{
    printf("No\n");
  }
  return 0;
}