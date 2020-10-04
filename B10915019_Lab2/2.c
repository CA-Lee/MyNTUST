#include <stdio.h>

int main(void) {
  printf("input:");
  int i,s;
  scanf("%d",&i);
  s=0;
  while(i>0){
    s+=i%10;
    i/=10;
  }
  printf("the sum is %d\n",s);
  return 0;
}