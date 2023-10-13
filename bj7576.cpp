#include<iostream>
#include<queue>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void BFS(int y,int x);

int BOX[1000][1000];
bool visit[1000][1000];
int n,m;

int main(){
    
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> BOX[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(BOX[i][j]>0 && !visit[i][j]){
                BFS(i,j);
            }
        }
    }

    int ans=BOX[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(BOX[i][j]==0){
                ans=-1;
                cout << -1;
                return 0;
            }
            else if(BOX[i][j]>0){
                ans=max(ans,BOX[i][j]);
            }
        }
    }

    cout << ans-1;
}

void BFS(int y,int x){
    queue<pair<int,int>> q1;
    visit[y][x]=true;
    q1.push(make_pair(y,x));

    while(!q1.empty()){
        pair<int,int> now=q1.front();
        q1.pop();

        int nowy=now.first;
        int nowx=now.second;

        for(int i=0;i<4;i++){
            int nexty=nowy+dy[i];
            int nextx=nowx+dx[i];

            if(-1<nexty<n && -1<nextx<m){
                if(!visit[nexty][nextx] && BOX[nexty][nextx]==0){
                    BOX[nexty][nextx]=BOX[nowy][nowx]+1;
                    visit[nexty][nextx]=true;
                    q1.push(make_pair(nexty,nextx));
                }
            }
        }
    }
}