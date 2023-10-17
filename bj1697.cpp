#include<iostream>
#include<queue>

#define MAX 100001
using namespace std;

int n,k;
bool visit[MAX];

void BFS(int s);

int main(){
    cin >> n >> k;
    visit[n]=true;
    BFS(n);

}

void BFS(int s){
    queue<pair<int,int>> q1;
    q1.push(make_pair(s,0));
    visit[s]=true;

    while(!q1.empty()){
        int n=q1.front().first;
        int cnt=q1.front().second;

        if(n==k){
            cout << cnt;
        }

        q1.pop();

        if(n-1>=0 && n-1<MAX){
            if(!visit[n-1]){
                visit[n-1]=true;
                q1.push(make_pair(n-1,cnt+1));
            }
        }

        if(n+1>=0 && n+1<MAX){
            if(!visit[n+1]){
                visit[n+1]=true;
                q1.push(make_pair(n+1,cnt+1));
            }
        }

        if(0<=n*2 && n*2<MAX){
            if(!visit[n*2]){
                visit[n*2]=true;
                q1.push(make_pair(n*2,cnt+1));
            }
        }
    }
}