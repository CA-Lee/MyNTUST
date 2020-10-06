#include <stdio.h>

int main(){
	int i,o;
	scanf("%d", &i);
	o = ((i/10)%10+7)%10;
	o *= 10;
	o += ((i)%10+7)%10;
	o *= 10;
	o += ((i/1000)+7)%10;
	o *= 10;
	o += ((i/100)%10+7)%10;
	printf("%04d\n", o);
}
