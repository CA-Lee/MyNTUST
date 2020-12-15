#include <stdio.h>

typedef struct address_t {
    int x;
    int y;
    int z;
    int m;
    char nickname[11];
}address_t ;

address_t scan_address(){
    address_t r;
    scanf("%d.%d.%d.%d %10s",&r.x,&r.y,&r.z,&r.m,r.nickname);
    return r;
}

void print_address(address_t o){
    printf("%d.%d.%d.%d %10s\n",o.x,o.y,o.z,o.m,o.nickname);
}

int local_address(address_t a,address_t b){
    if(a.x==b.x&&a.y==b.y)return 1;
    return 0;
}

int main(){
    address_t adds[100];
    for(int i=0;i<100;i++){
        adds[i] = scan_address();
        if(!(adds[i].x||adds[i].y||adds[i].z||adds[i].m))break;
    }
    puts("-----------------------");
    /**************/
    int book[100]={0};
    for(int i=0;i<100;i++){
        if(!(adds[i].x||adds[i].y||adds[i].z||adds[i].m))break;
        if(book[i])continue;
        for(int j=i+1;j<100;j++){
            if(!(adds[i].x||adds[i].y||adds[i].z||adds[i].m))break;
            if(book[i])continue;
            if(adds[i].x==adds[j].x&&adds[i].y==adds[j].y){
                book[j]=1;
                printf("Machines %s and %s are on the same local network.\n",adds[i].nickname,adds[j].nickname);
            }
        }
    }
    puts("-----------------------");
    /**************/
    for(int i=0;i<100;i++){
        if(!(adds[i].x||adds[i].y||adds[i].z||adds[i].m))break;
        print_address(adds[i]);
    }
}