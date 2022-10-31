#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int dp[501][501];
int cost[501];
int sum[501];
int t, k, i;
 
int dpf(int tx, int ty) {
    //여러개의 장을 동시에 할 때 메모리가 이용돼었는지 또는 기존에 연산된 부분이면 해당 값을 반환
    if (dp[tx][ty] != 0x3f3f3f3f){
        printf("a: %d\n",dp[tx][ty]);
        return dp[tx][ty];
    }
 
    if (tx == ty){
        printf("b\n");
        return dp[tx][ty] = 0;
    }
 
    if (tx + 1 == ty)
        //tx부터 ty까지의 최소합은 인접한 두 지점이므로 두 지접의 비용의 합을 반환한다.
        return dp[tx][ty] = cost[tx] + cost[ty];
 
    for (int mid = tx; mid < ty; ++mid) {
        //left는 한칸씩 때어내서 b case로 빼버리기 위해 이용
        int left = dpf(tx, mid);
        //right는 분리된 케이스 
        int right = dpf(mid + 1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right);
    }
 
    return dp[tx][ty] += sum[ty] - sum[tx - 1];
}
 
int main() {
    scanf("%d", &t);
    while (t--) {
        //dp 배열을 전부 매우 큰 값(0x3f3f3f3f)으로 초기화
        memset(dp, 0x3f, sizeof(dp));
        printf("%x\n",dp[0][0]);
        scanf("%d", &k);
        for (i = 1; i <= k; ++i) {
            //각 장에서의 행의 개수 입력
            scanf("%d", &cost[i]);
            //sum 배열은 1~i번째 인덱스 까지의 합
            sum[i] = sum[i - 1] + cost[i];
        }
        printf("%d\n", dpf(1, k));
    }
    return 0;
}