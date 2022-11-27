#include<stdio.h>
#define MAX(x,y) (x>y ? x:y)
#define MIN(x,y) (x>y ? y:x)
// 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
// 마지막 도착 계단은 반드시 밟아야 한다.
// 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

int main(){
    int n;
    scanf("%d",&n);

    int strs[n+1];
    strs[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&strs[i]);

    int dp[n+1];
    dp[0]=0;
    dp[1]=strs[1];
    dp[2]=strs[2]+strs[1];
    dp[3]=strs[3]+MAX(strs[1],strs[2]);

    //3이상부터는 그전 혹은 그전전 계단을 밟고 오르면 되는것
    for(int i=4;i<=n;i++){
        dp[i]=MAX(strs[i-1],strs[i-2])+strs[i];
    }

    printf("%d",dp[n]);
}