#include<iostream>
#include<queue>
#define MAX 1000001

bool visit[MAX];
int F,S,G,U,D;
int dF[2];
int ans=0;

using namespace std;

void BFS(int s);

int main(){
    cin >> F >> S >> G >> U >> D;
    dF[0]=U;
    dF[1]=D*-1;
    BFS(S);

    if(!visit[G]){
        cout << "use the stairs";
    }
    else{
        cout << ans;
    }
}

void BFS(int s){
    queue<pair<int,int>> q1;
    
    visit[s]=true;
    q1.push(make_pair(s,0));

    while(!q1.empty()){
        int f=q1.front().first;
        int cnt=q1.front().second;
        q1.pop();
        if(f==G){
            ans=cnt;
            break;
        }
        
        for(int i=0;i<2;i++){
            int nf=f+dF[i];
            if(nf>=1 && nf<=F){
                if(!visit[nf]){
                    visit[nf]=true;
                    q1.push(make_pair(nf,cnt+1));
                }
            }
        }
    }

}