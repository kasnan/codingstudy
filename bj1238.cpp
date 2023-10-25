#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int n,m,x;
// X에서 해당 도시까지의 거리
vector<int> To,From;

int s,e,v;

int main(){
    cin >> n >> m >> x;
    To=vector<int>(n+1,INT_MAX);
    From=vector<int>(n+1,INT_MAX);
    To[x]=0;
    From[x]=0;
    for(int i=0;i<m;i++){
        cin >> s >> e >> v;

    }
    // dij(x)로 x에서 해당 도시로 돌아가는 데 걸리는 비용 계산
    // 
}