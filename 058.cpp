#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

typedef pair<int,int> node;
typedef pair<int,int> edge;

vector<vector<node>> A;
vector<priority_queue<int,vector<int>,less<int>>> D;

priority_queue<edge,vector<edge>,greater<edge>> q1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;

    // 인접 리스트에는 인접 노드까지의 cost
    A.resize(n+1);
    for(int i=0;i<m;i++){
        int s,e,p;
        cin >> s >> e >> p;
        A[s].push_back(make_pair(e,p));
    }

    D.resize(n+1);
    D[1].push(0);

    q1.push(edge(0,1));

    while(!q1.empty()){
        edge cur = q1.top();
        q1.pop();

        // 현재 선택된 노드에 대해 모든 노드를 탐색
        for(node i : A[cur.second]){
            int next = i.first;
            int next_p = i.second;

            // 경로 크기 배열의 개수가 k보다 작은가 판단
            // k번째로 작은 경로, 즉 오름차순으로 k개까지만 삽입하면 된다.

            // k보다 작으면 일단 삽입한다.
            if(D[next].size()<k){
                D[next].push(cur.first+next_p);
                q1.push(edge(cur.first+next_p,next));
            }

            // k이상이면 top이 현재 선택된 노드를 기준의 경로 크기보다 큰지 판단
            // k번째가 더 크면 현재 주어진 경로를 포함해 k번째가 k+1번째가 되므로 삭제!
            // 크면 현재 경로 배열의 top을 삭제하고 현재 선택된 노드 기준 크기를 삽입

            // 우선순위 큐로 자동으로 오름차순으로 정렬되므로 k번째 크기만 판단하면 되기 때문
           
            else if(D[next].top() > cur.first+next_p){
                D[next].pop();
                D[next].push(cur.first+next_p);
                q1.push(edge(cur.first+next_p,next));
            }
        }
    }

    for(int i=1;i<n+1;i++){
        if(D[i].size()==k){
            cout << D[i].top() << endl;
        }
        else{
            cout << -1 << endl;
        }
    }


}