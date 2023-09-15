#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> A;
vector<int> ans;
vector<bool> visit;
vector<int> dist;

void BFS(int n);

int main(){
    int N,M,K,X;
    cin >> N >> M >> K >> X;

    A.resize(N+1);
    visit=vector<bool>(N+1,false);
    dist=vector<int>(N+1,0);

    // 그래프 정보 저장
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
    }

    // 거리가 K인 도시 찾기
    BFS(X);

    for(int i=1;i<dist.size();i++){
        if(dist[i]==K){
            ans.push_back(i);
        }
    }

    // 결과 출력
    if(ans.empty()){
        cout << -1 << endl;
    }
    else{
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << endl;
        }
    }

}

void BFS(int n){
    queue<int> q1;
    q1.push(n);
    visit[n]=true;

    while(!q1.empty()){
        int now = q1.front();
        q1.pop();
        for(int i : A[now]){
            if(!visit[i]){
                visit[i]=true;
                q1.push(i);
                // 현재 선택된 노드에 대해서 거리 1 추가
                dist[i]=dist[now]+1;
            }
        }

    }
    
}