#include<iostream>
#include<vector>
#include<queue>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visit;
static vector<int> tr;

void BFS(int n);

int main(){
    long N,M;
    cin >> N >> M;

    A.resize(N+1);
    visit.resize(N+1);
    tr.resize(N+1);

    // 그래프 정보 저장
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
    }

    fill(tr.begin(),tr.end(),0);

    for(int i=1;i<N+1;i++){
        // 각 탐색이 완료 후 방문 확인 벡터 초기화
        fill(visit.begin(),visit.end(),false);
        BFS(i);
        
    }
    
    // 모든 탐색이 종료 되면 신뢰도 배열 연산이 완료
    // 최대인 신뢰도 값을 찾고 해당 값을 가진 인덱스를 정답 배열에 넣기
    int max=0;
    for(int i=1;i<tr.size();i++){
        if(max<tr[i]){
            max=tr[i];
        }
    }

    for(int i=1;i<tr.size();i++){
        if(max==tr[i]){
            cout << i << " ";
        }
    }

}

void BFS(int n){
    queue<int> q1;
    q1.push(n);
    visit[n]=true;

    while(!q1.empty()){
        int now=q1.front();
        q1.pop();

        for(int i : A[now]){
            if(!visit[i]){
                visit[i]=true;
                // 인접 노드는 +1
                tr[i]++;
                q1.push(i);
            }
        }
    }
}