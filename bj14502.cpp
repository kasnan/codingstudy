#include<iostream>
#include<queue>
using namespace std;

int MAP[8][8];
int tmp[8][8];


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m,res;

void BFS();
void setwall(int cnt);

int main(){
    
    cin >> n >> m;
    res=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> MAP[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MAP[i][j]==0){
                memcpy(tmp,MAP,sizeof(MAP));
                tmp[i][j]=1;
                setwall(1);
                tmp[i][j]=0;
            }
        }
    }
    
    cout << res;
}

//벽을 세우는 함수
// 재귀 형식으로 3개를 세우자
void setwall(int cnt){
    //모든 벽을 세우고 안전 구역 개수 파악
    if(cnt==3){
        BFS();
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MAP[i][j]==0){
                tmp[i][j]=1;
                setwall(cnt+1);
                tmp[i][j]=0;
            }
        }
    }
    
}

//벽을 세우고 바이러스가 퍼졌을 때 남은 안전 구역을 파악하는 탐색
void BFS(){
    int spread[8][8];
    memcpy(spread,MAP,sizeof(MAP));
    queue<pair<int,int>> q1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MAP[i][j]==2){
                q1.push(make_pair(i,j));     
            }
        }
    }

    while(!q1.empty()){
        pair<int,int> now= q1.front();
        q1.pop();

        int y=now.first;
        int x=now.second;

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(-1<ny<n && -1<nx<m){
                if(spread[ny][nx]==0){
                    spread[ny][nx]=2;
                    q1.push(make_pair(ny,nx));
                }
            }
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(spread[i][j]==0){
                cnt++;
            }
        }
    }
    res=max(res,cnt);
}