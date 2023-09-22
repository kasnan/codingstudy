#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[10][10];
bool visit[10][10]={{false, }, };

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void BFS(int c,int r);

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }

    // 섬 구분
    // 모든 위치에서 BFS 수행
    for(int c=0;c<n;c++){
        for(int r=0;r<m;r++){
            if(!visit[c][r] && !map[c][r]){
                BFS(c,r);
            }
        }
    }
}