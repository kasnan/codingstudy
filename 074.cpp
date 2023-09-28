#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> Tree;
vector<bool> visit;
vector<int> P;
vector<int> D;

void BFS(int s);
int LCA(int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;
    // 인접 리스트 구현
    Tree.resize(n+1);
    visit.resize(n+1);
    P.resize(n+1);
    D.resize(n+1);

    // root는 1번 노드
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    BFS(1);

    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int res = LCA(a,b);
        cout << res << "\n";
    }
}



void BFS(int s){
    queue<int> q1;
    visit[s]=true;
    q1.push(s);
    
    int depth=1;
    int cnt=0;
    int size=1;

    while(!q1.empty()){
        int now = q1.front();
        q1.pop();

        for(int i : Tree[now]){
            if(!visit[i]){
                q1.push(i);
                visit[i]=true;

                // 이후 자식 노드들은 탐색 단계마다 깊이를 1씩 추가
                // 현재 선택된 노드의 인접 노드중 방문하지 않은, 즉 자식 노드
                P[i]=now;
                D[i]=depth;

            }
        }
        cnt++;
        if(cnt==size){
            cnt=0;
            size=q1.size();
            depth++;
        }
    }
}

int LCA(int a,int b){
    // 깊이가 다른 경우 높이 맞추고 진행해야함
    // 구현상의 용이함을 위해 깊이가 더 큰 노드를 a에 둬서 맞춤
    if(D[a]<D[b]){
        int tmp=a;
        a=b;
        b=tmp;
    }
    while(D[a]!=D[b]){
        a=P[a];
    }

    // 깊이가 같으면 각 단계에서 두 노드를 부모 노드로 이동
    // 같은 노드로 이동될 때까지 반복
    while(a!=b){
        a=P[a];
        b=P[b];
    }

    return a;
}