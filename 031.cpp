#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long N,K;
    cin >> N;
    cin >> K;

    long s=1;
    long e=K;
    long ans=0;
    while(s<=e){
        long mid = (s+e)/2;
        long cnt = 0;

        // 중앙값보다 작은 수의 개수를 행마다 탐색
        // 이 때 각 행의 수는 i*1 ~ i*N이다.
        // 각 행마다 브루트포스적인 접근 방법이 아니더라도
        // 중앙값에 각 행의 idx를 나눈 값을 N과 비교해서 구할 수 있다.
        for(int i=1;i<N+1;i++){
            cnt+=min(mid/i,N);
        }
        // 중앙값보다 작거나 같은 수가 K보다 적으면 더 큰 범위로 탐색
        if(cnt < K){
            s = mid + 1;
        }
        // K이상이면 일단 현재 단계의 탐색값을 저장하고 더 작은 범위로 탐색
        // 이는 더 작은 범위로 줄이기 위해 e 인덱스를 mid-1로 줄이고 나서
        // while문 탈출 조건이 완료되면 최종 단계에 해당
        else{
            ans=mid;
            e = mid - 1;
        }
    }

    cout << ans << endl;
}