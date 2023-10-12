#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<bool> visit;
vector<vector<int>> A;

void DFS(int s);
void BFS(int s);

int main(){
    int n,e,s;
    cin >> n >> e >> s;
    A.resize(n+1);
    visit.resize(n+1);

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for(int i=1;i<n+1;i++){
        sort(A[i].begin(),A[i].end());
    }

    fill(visit.begin(),visit.end(),false);
    cout << s << " ";
    DFS(s);
    cout << "\n";
    fill(visit.begin(),visit.end(),false);
    cout << s << " ";
    BFS(s);
}

void DFS(int s){
    visit[s]=true;
    
    for(int i:A[s]){
        if(!visit[i]){
            visit[i]=true;
            cout << i << " ";
            DFS(i);
        }
    }
}

void BFS(int s){
    queue<int> q1;
    visit[s]=true;
    q1.push(s);
    
    while(!q1.empty()){
        int now=q1.front();
        q1.pop();
        for(int next : A[now]){
            if(!visit[next]){
                cout << next << " ";
                visit[next]=true;
                q1.push(next);
            }
        }
    }
}