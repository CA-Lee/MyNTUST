#include <stdio.h>

int main(){
  double u2n,am;
  int s ;
  printf("Enter the exchange rate from USD to NTD:");//31.2
  scanf("%lf",&u2n);
  printf("Enter 0 to convert USD to NTD and 1 vice versa:");// 0
  scanf("%d",&s);
  if(s==0){
    printf("Enter the USD amount:");// 100
    scanf("%lf",&am);
    printf("$%.1lf USD is $%.0lf NTD\n", am, am*u2n);
  }else if(s==1){
    printf("Enter the NTD amount:");// 100
    scanf("%lf",&am);
    printf("$%.1lf NTD is $%.0lf USD\n", am, am/u2n);
  }
  //$100.0 USD is 3120 NTD.
}