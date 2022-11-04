#include<stdio.h>
#define MAX(x,y) (x>y ? x:y)

int main(){
    int A,B;
    scanf("%d %d",&A,&B);

    int tmp[3],index=0;
    while(A>0){
        tmp[index] = A%10;
        A/=10;
        index++;
    }
    int newA=tmp[0]*100+tmp[1]*10+tmp[2];
    index=0;
    while(B>0){
        tmp[index] = B%10;
        B/=10;
        index++;
    }
    int newB=tmp[0]*100+tmp[1]*10+tmp[2];
    printf("%d",MAX(newA,newB));    
}