#include <stdio.h>
#include <math.h>

int det(int i){
    //printf("\r%d\r",i);
	for(int j = 2; j <= sqrt(i);j++){
		if(i%j == 0){
			return 0;
		}
	}
    
    int rev=0,k=i;
    while(k){
        rev*=10;
        rev+=k%10;
        k/=10;
    }
    if(rev!=i)return 0;
	
    printf("%d ",i);
    return 1;
}

int main(){
    int count=0,i=1;
    while(count<120){
        //printf("%d\n",count);
        while(!det(i))i++;
        i++;
        count++;
        if(((count%10)==0)&&(count>1))printf("\n");
    }
}