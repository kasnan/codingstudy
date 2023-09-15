#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> A;
vector<bool> visit;
vector<int> tr;

void BFS(int n);

int main(){
    int N,M;
    cin >> N >> M;

    A.resize(N+1);
    visit=vector<bool>(N+1,false);
    tr=vector<int>(N+1,0);

    // 그래프 정보 저장
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
    }

    for(int i=1;i<N+1;i++){
        BFS(i);
        // 각 탐색이 완료 후 방문 확인 벡터 초기화
        fill(visit.begin(),visit.end(),false);
    }
    
    // 모든 탐색이 종료 되면 신뢰도 배열 연산이 완료
    // 최대인 신뢰도 값을 찾고 해당 값을 가진 인덱스를 정답 배열에 넣기
    int max=tr[1];
    for(int i=2;i<tr.size();i++){
        if(max<tr[i]){
            max=tr[i];
        }
    }

    vector<int> ans;

    for(int i=1;i<tr.size();i++){
        if(max==tr[i]){
            ans.push_back(i);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
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
                q1.push(i);
                // 인접 노드는 현재 선택된 노드의 신뢰도에 +1
                tr[i]=tr[now]+1;
            }
        }
    }
}