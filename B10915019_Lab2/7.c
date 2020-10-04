#include <stdio.h>

int main(void) {
  char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday"};
  int q,m,j,k,h;
  printf("y:");
  scanf("%d",&j);
  printf("m:");
  scanf("%d",&m);
  printf("d:");
  scanf("%d",&q);
  if(m<3){
    m+=12;
    j-=1;
  }
  k=j%100;
  j/=100;
  h = (k+q+(26*(m+1)/10)+(k/4)+(j/4)+5*j)%7;
  printf("Day of the week is %s\n",days[h]);
  return 0;
}