#include <stdio.h>

int main(){
	int i[10],m=0;
	for(int j = 0; j < 10;j++){
		scanf("%d", &i[j]);
		m = i[m] < i[j]? j:m;
	}
	printf("%d\n", i[m]);
	i[m] = -1;
	m=0;
	for(int j = 0; j < 10;j++){
		m = i[m] < i[j]? j:m;
	}
	printf("%d\n", i[m]);

}
