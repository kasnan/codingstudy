#include<stdio.h>

void computeVary(){
    int n;
    scanf("%d",&n);
    int dp[n+1];
    dp[1]=1; dp[2]=2; dp[3]=4;
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    printf("%d\n",dp[n]);
}

int main(){
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        computeVary();
    }
}