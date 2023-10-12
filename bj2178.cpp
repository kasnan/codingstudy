#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int MAZE[101][101];
bool visit[101][101];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void BFS(int sy,int sx);
int n,m;
int step=0;

typedef

int main(){
    
    cin >> n >> m;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin >> MAZE[i][j];
        }
    }

    visit[1][1]=true;
    BFS(1,1);

    cout << step;
    
}

