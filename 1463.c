#include<stdio.h>
#define MIN(x,y) (x>y ? y:x)
int main(){
    int N;
    scanf("%d",&N);
    int dp[N];
    dp[1]=0;
    for(int i=2;i<=N;i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0){
            dp[i]=MIN(dp[i],dp[i/2]+1);
        }
        if(i%3==0){
            dp[i]=MIN(dp[i],dp[i/3]+1);
        }
    }
    printf("%d",dp[N]);
}