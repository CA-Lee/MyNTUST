#include <stdio.h>

void sort (int m[][2], int row){
    int sorted_id=0;
    for(int i=0;i<row-1;i++,sorted_id++){
        int max_id=sorted_id;
        for(int j=sorted_id+1;j<row;j++){
            if(m[j][0]>m[max_id][0])max_id=j;
            else if(m[j][0]==m[max_id][0] && m[j][1]>m[max_id][1])max_id=j;
        }
        if(max_id!=sorted_id){
            int temp[]={m[max_id][0],m[max_id][1]};
            m[max_id][0] = m[sorted_id][0];
            m[max_id][1] = m[sorted_id][1];
            m[sorted_id][0] = temp[0];
            m[sorted_id][1] = temp[1];
        }
    }
}

int main(){
    puts("Enter the number of value-pairs:");
    int n;
    scanf("%d",&n); //3
    int a[n][2];
    for(int i=0;i<n;i++){
        printf("Input value-pair:");
        scanf("%d%d",&a[i][0],&a[i][1]);// 4  2
/*Input value-pair: 1  7
Input value-paer:4  5
*/  }
    sort(a,n);
    puts("The sorted result is");
    printf("{");
    for(int i=0;i<n;i++){
        printf("{%d, %d}", a[i][0], a[i][1]);
        if(i!=n-1)printf(", ");
    }
    printf("}\n");
}