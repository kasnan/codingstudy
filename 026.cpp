#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

static vector<vector<int>> A;
static vector<bool> ch;


void DFS(int v);
void BFS(int i);

int main(){

    int N,M,V;
    cin >> N >> M >> V;

    A.resize(N+1);

    int a,b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for(int i=1;i<N+1;i++){
        sort(A[i].begin(),A[i].end());
    }

    ch=vector<bool>(N+1,false);
    DFS(V);
    fill(ch.begin(),ch.end(),false);
    BFS(V);

}

void DFS(int v){
    ch[v]=true;
    cout << v << endl;
    for(int i : A[v]){

        if(!ch[i]){
            DFS(i);
        }
    }
}

void BFS(int v){
    queue<int> q1;

    q1.push(v);
    ch[v]=true;

    while(!q1.empty()){
        int front=q1.front();
        q1.pop();
        cout << front << endl;
        for(int i : A[front]){
            if(!ch[i]){
                q1.push(i);
                ch[i]=true;
            }
        }
    }
}