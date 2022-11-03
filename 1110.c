#include<stdio.h>

int getSum(int n){
    int right;
    int sum=n/10+n%10;

    right=sum%10;
    return right;
}

int main(){
    int N;
    scanf("%d",&N);
    int cnt=0;
    int right,sum;
    int result=N;
    if(N<10){
        result=result*10+result;
        cnt++;
    }
    
    while(1){
        if(result == N && N<10)
            break;    
        right=result%10;
        sum=getSum(result);
        result=right*10+sum;
        cnt++;
        if(result == N)
            break;        
    }

    printf("%d",cnt);
}