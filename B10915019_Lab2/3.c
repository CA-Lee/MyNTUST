#include <stdio.h>

int main(void) {
  double x,y;
  printf("x:");
  scanf("%lf",&x);
  printf("y:");
  scanf("%lf",&y);
  if(x>=0 && y>=0){
    if(y<=((-0.5*x)+100)){
    printf("The point is in the triangle.\n");
    return 0;
    }
  }
  printf("The point is not in the triangle.\n");
  return 0;
}