#include <stdio.h>

int det(int i){
	for(int j = 2; j <= i/2;j++){
		if(i%j == 0){
			return 0;
		}
	}
    return 1;
}

int main(){
    int i = 2;
    while(i<1208){
        if(det(i)&&det(i+2))printf("(%d, %d)\n", i, i+2);
        i++;
    }
}