#include<iostream>
#include<queue>
using namespace std;

int MAP[26][26];
bool visit[26][26];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int apt_group=0;

void BFS(int y,int x);

int main(){
    int n;
    cin >> n;
    for(int i=1;i<n+1;i++){
        string line;
        cin >> line;
        for(int j=1;j<n+1;j++){
            MAP[i][j]=line[j-1]-'0';
        }
    }

}

void BFS(int y,int x){
    queue<pair<int,int>> q1;
    
}