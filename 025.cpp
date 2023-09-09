#include<iostream>
#include<vector>

using namespace std;

static vector<vector<int>> P;
static vector<bool> V;

void DFS(int v,int dep);

bool arrive = false;
int N, M;

int main(){    
    int ans=0;
    cin >> N >> M;

    P.resize(N);
    V = vector<bool>(N,false);

    int a,b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        P[a].push_back(b);
        P[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        DFS(i,1);
        if(arrive){
            ans=1;
            break;
        }
    }

    cout << ans << endl;
    
}

void DFS(int v,int dep){
    if(dep==5 || arrive){
        arrive = true;
        return;
    }
    
    V[v]=true;
    for(int i : P[v]){
        if(V[i]==false){
            DFS(i,dep+1);
        }
    }
    V[v]=false;
}