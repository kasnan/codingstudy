#include<iostream>
#include<queue>
#include<memory.h>

#define MAX 100
using namespace std;

int map[MAX][MAX], tmp[MAX][MAX];
bool visit[MAX][MAX];
int n,maxh=0;
int reg,ans;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void BFS(int y,int x);
void rain(int h);

int main(){
    cin >> n;
    ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            maxh=max(maxh,map[i][j]);  
        }
    }

    for(int i=1;i<maxh+1;i++){
        memcpy(tmp,map,sizeof(map));
        rain(i);
    }

    cout << ans;


}


void rain(int h){
    reg=0;
    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tmp[i][j]<h){
                tmp[i][j]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j] && tmp[i][j]!=-1){
                BFS(i,j);
                reg++;
            }
        }
    }

    ans=max(ans,reg);
}

void BFS(int y,int x){
    queue<pair<int,int>> q1;
    visit[y][x]=true;

    q1.push(make_pair(y,x));
    while(!q1.empty()){
        int y=q1.front().first;
        int x=q1.front().second;
        q1.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny>=0 && ny<n && nx>=0 && nx<n){
                if(!visit[ny][nx] && tmp[ny][nx]!=-1){
                    visit[ny][nx]=true;
                    q1.push(make_pair(ny,nx));
                }
            }
        }
    }
    
}

