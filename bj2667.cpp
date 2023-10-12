#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int MAP[26][26];
bool visit[26][26];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int n;
int apt_group=0;
vector<int> grp;


int BFS(int y,int x);

int main(){
    cin >> n;
    for(int i=1;i<n+1;i++){
        string line;
        cin >> line;
        for(int j=1;j<n+1;j++){
            MAP[i][j]=line[j-1]-'0';       
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(!visit[i][j] && MAP[i][j]!=0){
                grp.push_back(BFS(i,j));
                apt_group++;
            }
        }
    }

    sort(grp.begin(),grp.end());
    cout << apt_group << endl;
    for(int i=0;i<grp.size();i++){
        cout << grp[i] << endl;
    }

    

}

int BFS(int y,int x){
    int cnt=0;
    queue<pair<int,int>> q1;
    visit[y][x]=true;
    q1.push(make_pair(y,x));

    while(!q1.empty()){
        pair<int,int> now=q1.front();
        q1.pop();
        cnt++;
        int nowy=now.first;
        int nowx=now.second;
        MAP[nowy][nowx]+=apt_group;

        for(int i=0;i<4;i++){
            int nexty=nowy+dy[i];
            int nextx=nowx+dx[i];

            if(0<nexty<n+1 && 0<nextx<n+1){
                if(!visit[nexty][nextx] && MAP[nexty][nextx]!=0){
                    visit[nexty][nextx]=true;
                    q1.push(make_pair(nexty,nextx));
                }
            }

        }
    }

    return cnt;
}