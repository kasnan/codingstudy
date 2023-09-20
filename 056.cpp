#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

typedef pair<int,int> edge;

vector<vector<pair<int,int>>> A;
vector<int> D;
vector<bool> visit;

priority_queue<edge,vector<edge>,greater<edge>> q1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v,e;
    cin >> v >> e;

    A.resize(v+1);
    visit=vector<bool>(v+1,false);

    // 시작 노드
    int k;
    cin >> k;

    // 인접 리스트 저장
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(make_pair(v,w));
    }

    // 최단 거리 배열 초기화
    D=vector<int>(v+1,INT_MAX);
    D[k]=0;

    // 우선순위 큐에는 (거리,도시번호)로 삽입
    // 거리에 따라 정렬하기 위함
    q1.push(make_pair(0,k));

    while(!q1.empty()){
        edge now = q1.top();
        q1.pop();
        int cur = now.second;

        if(visit[cur]){
            continue;
        }
        visit[cur]=true;

        for(edge nedge : A[cur]){
            int next=nedge.first;
            int next_d=nedge.second;

            if(D[next]>D[cur]+next_d){
                D[next]=D[cur]+next_d;
                q1.push(make_pair(D[next],next));
            }
        }
    }

    for(int i=1;i<visit.size();i++){
        if(visit[i]){
            cout << D[i] << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }

}