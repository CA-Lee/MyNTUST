#include <stdio.h>

int main(){
	double i;
	printf("Enter sales in dollars (-1 to end):");
	scanf("%lf", &i);
	while(i != -1){
		printf("Salary is: $%.2lf\n", 200 + (i*0.09));
		printf("Enter sales in dollars (-1 to end):");
		scanf("%lf", &i);
	}
}
