#include <stdio.h>

int main(void) {
  char* res[] = {"Circle2 is inside circle1.\n","Circle2 is overlap circle1.\n","Circle2 does not overlap circle1.\n"};
  double x1,y1,r1,x2,y2,r2;
  printf("Enter circle1’s center x-, y-coordinates, and radius:");
  scanf("%lf %lf %lf",&x1,&y1,&r1);
  printf("Enter circle2’s center x-, y-coordinates, and radius:");
  scanf("%lf %lf %lf",&x2,&y2,&r2);
  double rr,d;
  d= (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
  rr=(r1+r2)*(r1+r2);
  if(rr<d)printf("%s",res[2]);
  else if (d>(r1-r2)*(r1-r2)) printf("%s", res[1]);
  else printf("%s",res[0]);
  return 0;
}