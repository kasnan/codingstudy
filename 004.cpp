#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N,M;
    int x1,y1,x2,y2;
    cin >> N >> M;
    vector<vector<int>> A(N+1,vector<int>(N+1,0));
    vector<vector<int>> D(N+1,vector<int>(N+1,0));

    // 2차원 구간합 구하기
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> A[i][j];
            D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + A[i][j];
        }
    }

    // (X1,Y1) ~ (X2,Y2) 직사각형 범위 내부의 원소들의 합
    // 좌측 상단을 기준으로 좌측과 상단의 범위 밖 원소들에 해당하는 구간합을 없애고,
    // 중복되어 뺄셈되는 구간합 부분을 더한다
    for(int i=1;i<=M;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int result = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y2-1];
        cout << result << endl;
    }

    

    
}