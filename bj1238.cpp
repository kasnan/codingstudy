#include <iostream>
#include <vector>
#include <queue>
 
#define pii pair<int, int>
 
using namespace std;
 
 
int N, M, X;
const int INF = 1e9+7;
vector<pii > A[2][1001]; 
vector<int> dist[2];
 
void input(){
    int u, v, t;
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> t;
        A[0][u].push_back(make_pair(t, v));
        A[1][v].push_back(make_pair(t, u));
    }
    dist[0].resize(N+1, INF);
    dist[1].resize(N+1, INF);
}
 
void dij(int k){
    dist[k][X] = 0;
    
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    pq.push({0, X});
    
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        if(cur_dist > dist[k][cur_node]) continue;
        
        for(int i = 0; i < A[k][cur_node].size(); i++){
            int next_node = A[k][cur_node][i].second;
            int next_dist = cur_dist + A[k][cur_node][i].first;
            
            if(next_dist < dist[k][next_node]){
                dist[k][next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    // 각 마을 -> X
    dij(1);
    // X -> 각 마을
    dij(0); 
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, dist[0][i] + dist[1][i]);
    }
    
    cout << ans;
    
    return 0;
}