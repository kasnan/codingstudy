#include<stdio.h>

int main(){
    int input[6];
    int set[]={1,1,2,2,2,8};

    for(int i=0;i<6;i++){
        scanf("%d",&input[i]);
    }
    for(int i=0;i<sizeof(set)/sizeof(int);i++){
        printf("%d ",-input[i]+set[i]);
    }

}