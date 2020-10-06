#include <stdio.h>

int main(){
	int i;
	scanf("%d", &i);
	for(int j = 2; j <= i/2;j++){
		if(i%j == 0){
			printf("is not prime\n");
			return 0;
		}
	}
	printf("it's prime\n");
}
