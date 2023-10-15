#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int visit[100];
vector<vector<int>> A;
int n,p1,p2,m;

void BFS(int s);

int main(){
    cin >> n;
    A.resize(n+1);
    cin >> p1 >> p2;
    cin >> m;

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    memset(visit,0,sizeof(visit));
    BFS(p1);

    if(!visit[p2]){
        visit[p2]=-1;
    }

    cout << visit[p2];

}

void BFS(int s){
    queue<int> q1;
    q1.push(s);
    visit[s]=0;

    while(!q1.empty()){
        int now=q1.front();
        q1.pop();
        for(int next : A[now]){
            if(visit[next]==0){
                q1.push(next);
                visit[next]=visit[now]+1;
            }
        }
    }
}