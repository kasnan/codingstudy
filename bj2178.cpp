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

int main(){
    cin >> n >> m;
    for(int i=1;i<n+1;i++){
        string mzline;
        cin >> mzline;
        for(int j=1;j<m+1;j++){
            MAZE[i][j]=mzline[j-1]-'0';
        }
    }

    visit[1][1]=true;
    BFS(1,1);

    cout << MAZE[n][m];   
}

void BFS(int sy,int sx){
    queue<pair<int,int>> q1;
    q1.push(make_pair(sy,sx));

    while(!q1.empty()){
        pair<int,int> now = q1.front();
        q1.pop();

        int nowy=now.first;
        int nowx=now.second;

        for(int i=0;i<4;i++){
            int nexty=nowy+dy[i];
            int nextx=nowx+dx[i];

            if(0<nexty<n+1 && 0<nextx<m+1){
                if(!visit[nexty][nextx] && MAZE[nexty][nextx]!=0){
                    visit[nexty][nextx]=true;
                    MAZE[nexty][nextx]=MAZE[nowy][nowx]+1;
                    q1.push(make_pair(nexty,nextx));
                }
            }
        }
    }
}

