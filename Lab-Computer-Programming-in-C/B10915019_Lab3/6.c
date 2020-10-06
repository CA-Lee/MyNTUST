#include <stdio.h>
#include <math.h>

int main(){
	int t1,t2,t3;
	scanf("%d %d %d",&t1,&t2,&t3);
	if(t1>=t2 && t1 >= t3){
		if(t1 < (t2+t3))printf("yes\n");
		else printf("no\n");
	}else if(t2 >= t1 && t2 >= t3){
		if(t2 < (t1+t3))printf("yes\n");
		else printf("no\n");
	}else if(t3 >= t1 && t3 >= t2){
		if(t3 < (t2+t1))printf("yes\n");
		else printf("no\n");
	}
}
