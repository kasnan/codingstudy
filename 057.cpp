#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

typedef pair<int,int> edge;

vector<vector<pair<int,int>>> A;
vector<bool> visit;
vector<int> D;

priority_queue<edge,vector<edge>,greater<edge>> q1;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    A.resize(n+1);
    visit=vector<bool>(n+1,0);
    D=vector<int>(n+1,INT_MAX);

    for(int i=0;i<m;i++){
        int s,e,p;
        cin >> s >> e >> p;
        A[s].push_back(make_pair(e,p));
    }

    int a,b;
    cin >> a >> b;
    D[a]=0;

    // 큐에는 각 노드가 (거리, 도시)순서로 삽입 및 삭제
    q1.push(edge(0,a));
    
    while(!q1.empty()){
        edge current = q1.top();
        q1.pop();

        int now = current.second;
        int now_d = current.first;

        if(visit[now]){
            continue;
        }
        visit[now]=true;

        for(pair<int,int> nextnode : A[now]){
            int next = nextnode.first;
            int next_d = nextnode.second;

            if(D[next] > D[now]+next_d){
                D[next]=D[now]+next_d;
                q1.push(edge(D[next],next));
            }
        }
    }

    cout << D[b] << endl;
}