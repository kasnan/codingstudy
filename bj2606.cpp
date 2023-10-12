#include<iostream>
#include<vector>
using namespace std;

bool visit[101];
vector<vector<int>> A;

void DFS(int n);

int main(){
    int n,e;
    cin >> n >> e;
    A.resize(n+1);

    for(int i=1;i<e+1;i++){
        int s,e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    DFS(1);

    int cnt=0;
    for(int i=1;i<n+1;i++){
        if(visit[i]){
            cnt++;
        }
    }

    cout << cnt-1;
}

void DFS(int n){
    visit[n]=true;
    for(int next : A[n]){
        if(!visit[next]){
            DFS(next);
        }
    }
}
