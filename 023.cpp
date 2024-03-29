#include<iostream>
#include<vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> C;

void DFS(int v){
    if(C[v]){
        return;
    }
    C[v]=true;
    for(int i : A[v]){
        if(C[i] == false){
            DFS(i);
        }
    }

}

int main(){
    int N,M;
    cin >> N >> M;

    A.resize(N+1);
    C = vector<bool>(N+1,false);

    // 그래프 각 노드에 대한 인접 노드 저장
    int u,v;
    for(int i=0;i<M;i++){
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    int check=0;

    // 방문하지 않은 노드임을 확인하고 DFS실행
    for(int i=1;i<N+1;i++){
        if(!C[i]){
            check++;
            DFS(i);
        }
    }
    cout << check << endl;
}