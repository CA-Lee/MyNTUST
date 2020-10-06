#include <stdio.h>

int main(){
	double i, i1;
	printf("Enter # of hours worked (-1 to end):");
	scanf("%lf", &i);
	while(i != -1){
		printf("Enter hourly rate of the worker ($00.00):");
		scanf("%lf", &i1);
		printf("Salary is: $%.2lf\n",
			(i > 40 ) ? (i - 40)*i1*1.5 + 40*i1 : i*i1
		);
		printf("Enter # of hours worked (-1 to end):");
		scanf("%lf", &i);
	}
}
