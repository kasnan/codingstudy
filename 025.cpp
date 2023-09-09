#include<iostream>
#include<vector>

using namespace std;

static vector<vector<int>> P;
static vector<bool> V;

void DFS(int v,int dep);

bool arrive = false;
int N, M;

int main(){    
    int ans=0;
    cin >> N >> M;

    P.resize(N);
    V = vector<bool>(N,false);

    // 그래프 정보 저장
    int a,b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        P[a].push_back(b);
        P[b].push_back(a);
    }

    // 처음부터 모든 노드 DFS 실행
    for(int i=0;i<N;i++){
        DFS(i,1);
        if(arrive){
            ans=1;
            break;
        }
    }

    cout << ans << endl;
    
}

void DFS(int v,int dep){
    // 깊이가 5에 도달하면 조건 충족
    // 또는 현재 실행중인 탐색과 무관하게 이미 조건이 충족된 탐색이 생기면
    // 탐색 중단
    if(dep==5 || arrive){
        arrive = true;
        return;
    }
    
    V[v]=true;
    // 해당 노드의 인접 리스트에서 인접 노드들에 대해
    // DFS 계속 진행
    // 물론 방문 X인 노드
    for(int i : P[v]){
        if(V[i]==false){
            DFS(i,dep+1);
        }
    }

    // 다른 브랜치에서 탐색했을 때도 고려해야 하므로
    // 방문 기록 삭제
    V[v]=false;
}