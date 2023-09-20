#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> A;
vector<int> D;
vector<int> T;
vector<int> ANS;

queue<int> TOP;

void topsort();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    A.resize(n+1);
    T.resize(n+1);
    D=vector<int>(n+1,0);
    ANS=vector<int>(n+1,0);

    for(int i=1;i<n+1;i++){
        int time;
        cin >> time;
        T[i]=time;

        int prebuild=0;
        while(true){
            cin >> prebuild;
            if(prebuild==-1){
                break;
            }
            A[prebuild].push_back(i);
            D[i]++;
        }
    }

    topsort();
    for(int i=1;i<n+1;i++){
        cout << ANS[i] + T[i] << endl;
    }


}

// 위상 정렬은 해당 건물 짓기 전 지어져야 하는 모든 건물들이 지어지는 시간을 구하기 위함
// 진입 차수가 0인 건물은 바로 지을 수 있으므로 준비 시간, 즉 이전 건물의 건설 완료 시간이 0
// 진입 차수가 0보다 큰 건물은 진입 차수가 0이 될 때까지 준비 시간을 계속 변화한다.

// max 함수는 확실한 준비 시간을 구하기 위함
// 현재 저장된 준비 시간이 각 루프마다 주어지는 새로운 준비 시간보다 큰 경우, 현재 저장된 준비 시간이 확실한 준비 시간이다.
void topsort(){
    for(int i=1;i<D.size();i++){
        if(D[i]==0){
            TOP.push(i);
        }
    }

    while(!TOP.empty()){
        int now = TOP.front();
        TOP.pop();

        for(int i : A[now]){
            D[i]--;
            ANS[i]=max(ANS[i],ANS[now]+T[now]);
            if(D[i]==0){
                TOP.push(i);
            }
        }
    }
    
}