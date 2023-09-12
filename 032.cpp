#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 두 비교할 인자에 대해 우선도를 판단한다고 생각하면 쉽다
// 아래 함수에서는 더 큰 함수에 높은 우선도를 부여한다는 것
// 더 높은 우선도가 더 우선해서 정렬되어 먼저 배치된다!
bool cmp(int i, int j){
    return i > j;
}

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    // 오름차순으로 주어지므로 내림차순으로 정렬해도 좋고
    // 안해도 탐색 인덱스를 거꾸로 해도 되니 뭐 필수는 아닌 코드
    sort(A.begin(),A.end(),cmp);
    
    // 최소 동전의 수를 사용하려면 큰 값부터 사용한다.
    // 루프문을 사용해서 카운트를 반복하고 종료 조건에 탈출
    // 종료 조건을 목표 값에 도달할 때로
    int cnt=0;
    int nowcnt;
    while (K>0)
    {
        for(int i=0;i<N;i++){
            if(A[i]<=K){
                nowcnt=K/A[i];
                K=K%A[i];
                cnt+=nowcnt;
            }
        }
    }
    cout << cnt << endl;


}