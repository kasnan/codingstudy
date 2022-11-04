#include<stdio.h>

int main(){
    int A,B,C;
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);

    int result=A*B*C;
    int cnt[10]={0,};
    while(result>0){
        int tmp=result%10;
        cnt[tmp]++;
        result/=10;
    }

    for(int i=0;i<10;i++){
        printf("%d\n",cnt[i]);
    }
}