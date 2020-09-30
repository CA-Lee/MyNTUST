#include <stdio.h>

int main(void) {
  double p0x,p0y,p1x,p1y,p2x,p2y;
  printf("p0:");
  scanf("%lf %lf",&p0x,&p0y);
  printf("p1:");
  scanf("%lf %lf",&p1x,&p1y);
  printf("p2:");
  scanf("%lf %lf",&p2x,&p2y);
  double res = (p1x-p0x)*(p2y-p0y)-(p2x-p0x)*(p1y-p0y);
  if(res>0){
  printf("(%.1lf, %.1lf) is on the left side of the line from (%.1lf, %.1lf) to (%.1lf, %.1lf)\n", p2x,p2y,p0x,p0y,p1x,p1y);
  }else if (res == 0){printf("(%.1lf, %.1lf) is on the line from (%.1lf, %.1lf) to (%.1lf, %.1lf)\n\n", p2x,p2y,p0x,p0y,p1x,p1y);
  }else printf("(%.1lf, %.1lf) is on the right side of the line from (%.1lf, %.1lf) to (%.1lf, %.1lf)\n", p2x,p2y,p0x,p0y,p1x,p1y);
  
  
  return 0;
}