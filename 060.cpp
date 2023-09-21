#include<iostream>
#include<vector>
#include<tuple>
#include<limits.h>

using namespace std;

typedef tuple<int,int,int> edge;

vector<edge> A;
vector<long> D;
vector<long> G;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,a,b,m;
    cin >> n >> a >> b >> m;

    A.resize(m);
    for(int i=0;i<m;i++){
        int s,e,w;
        cin >> s >> e >> w;
        A[i]=edge(s,e,w);
    }

    // 도시에 도착하면 얻는 수익
    // 양수의 가중치에 해당된다.
    G=vector<long>(n);
    for(int i=0;i<n;i++){
        cin >> G[i];

    }

    // 거리 배열
    D=vector<long>(n,LONG_MIN);
    // 도시에도 가중치가 존재하므로 시작 노드의 거리는 0이 아니다.
    D[a]=G[a];

    // 양수 사이클이 충분히 전파되도록 충분히 큰 횟수만큼 반복
    // 노드의 개수는 최대 50개 이므로 n+50만큼 반복한다.

    // 최대 가능한 엣지의 개수, 즉 n-1번만큼 반복한 이후에는 양수 사이클에 해당된다.
    for(int i=0;i<n+50;i++){
        for(int j=0;j<m;j++){
            edge cur = A[j];
            int s = get<0>(cur);
            int e = get<1>(cur);
            int w = get<2>(cur);

            if (D[s] == LONG_MIN){
                continue;
            }
            else if(D[s] == LONG_MAX){
                D[e]=LONG_MAX;
            }
            // 이동하면서 이용하는 엣지의 음수의 가중치와
            // 도시에 도착하면서 얻는 도착 노드의 양수의 가중치를
            // 함께 고려한다.
            else if(D[e] < D[s]+G[e]-w){
                D[e]=D[s]+G[e]-w;
                // 엣지가 가질 수 있는 최대 갯수만큼 반복한 이후의 경우이다
                // 해당 개수만큼 반복했는데도 업데이트가 가능하다면
                // 해당 노드의 거리 값이 계속해서 커진다,즉 양수 루프에 연결된 노드이다.
                if(i>=n-1){
                    D[e]=LONG_MAX;
                }
            }
        }
    }

    if(D[b]==LONG_MIN){
        cout << "gg" << endl;
    }
    else if(D[b]==LONG_MAX){
        cout << "Gee" << endl;
    }
    else{
        cout << D[b] << endl;
    }


}