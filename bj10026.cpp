#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int orig[100][100];
int blind[100][100];
bool visit[100][100];

int n;
int orig_ans=0, blind_ans=0;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void BFS(int arr[][100],int y,int x,int *c);
void BFS_blin();

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        string line;
        cin >> line;
        for(int j=0;j<n;j++){
            if(line[j]=='R'){
                orig[i][j]=-1;
                blind[i][j]=-1;
            }
            else if(line[j]=='G'){
                orig[i][j]=-2;
                blind[i][j]=-1;
            }
            else{
                orig[i][j]=-3;
                blind[i][j]=-2;
            }
        }
    }

    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                BFS(orig,i,j,&orig_ans);
            }
        }
    }

    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                BFS(blind,i,j,&blind_ans);
            }
        }
    }

    cout << orig_ans << " " << blind_ans;

}

void BFS(int arr[][100],int y,int x,int *c){
    int reg=arr[y][x];
    int cnt=*c;
    queue<pair<int,int>> q1;
    visit[y][x]=true;
    arr[y][x]=cnt;
    q1.push(make_pair(y,x));

    while(!q1.empty()){
        pair<int,int> now = q1.front();
        q1.pop();
        
        int nowy=now.first;
        int nowx=now.second;
        

        for(int i=0;i<4;i++){
            int ny=nowy+dy[i];
            int nx=nowx+dx[i];

            if(-1<ny && ny<n && -1<nx && nx<n){
                if(!visit[ny][nx] && arr[ny][nx]==reg){
                    visit[ny][nx]=true;
                    arr[ny][nx]=cnt;
                    q1.push(make_pair(ny,nx));
                }
            }
        }
    }

    cnt++;
    *c=cnt;
    
}