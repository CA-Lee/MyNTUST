#include <stdio.h>

void det(int i){
	for(int j = 2; j <= i/2;j++){
		if(i%j == 0){
			return;
		}
	}
	printf("%d\n",i);
}

int main(){
    for(int i=1;i<1001;i++)det(i);
}