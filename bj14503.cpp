#include<iostream>
#include<queue>
using namespace std;

int room[50][50];
int N,M;
int sr,sc,d;
int cnt=0;

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

void BFS(int r,int c);

int main(){
    cin >> N >> M;
    cin >> sr >> sc >> d;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> room[i][j];
        }
    }

    BFS(sr,sc);
    cout << cnt;
}

void BFS(int r,int c){
    queue<pair<int,int>> q1;
    q1.push(make_pair(r,c));
    bool proc=true;
    int nr,nc;
    while(!q1.empty()){
        int r=q1.front().first;
        int c=q1.front().second;

        q1.pop();
        if(room[r][c]==0){
            // 청소하면 해당 위치는 2로 변경
            room[r][c]=2;
            cnt++;
        }
        // 인접한 4칸에 청소되어있지 않은 칸이 있는 지 탐색
        for(int i=0;i<4;i++){
            nr=r+dr[i];
            nc=c+dc[i];

            if(nr>=0 && nr<N && nc>=0 && nc<M){
                if(room[nr][nc]==0){
                    proc=false;
                    d=(d+4-1)%4;
                    break;
                }
            }   
        }
        if(proc){
            nr=r-dr[d];
            nc=c-dc[d];

            if(nr>=0 && nr<N && nc>=0 && nc<M){
                if(room[nr][nc]!=1){
                    q1.push(make_pair(nr,nc));
                }
                else{
                    return;
                }
            }

        }
        else{
            nr=r+dr[d];
            nc=c+dc[d];
            if(nr>=0 && nr<N && nc>=0 && nc<M){
                if(room[nr][nc]==0){
                    q1.push(make_pair(nr,nc));
                }
                else{
                    q1.push(make_pair(r,c));
                }
            }
        }
        proc=true;
    }
}