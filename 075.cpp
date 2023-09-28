#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

vector<vector<int>> Tree;
vector<bool> visit;
vector<int> D;
int LCA[21][100001];
int n,m,k;

void BFS(int s);
int LCAFunc(int a,int b);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    // 인접 리스트 구현
    Tree.resize(n+1);
    
    // root는 1번 노드
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    // 탐색으로 각 노드의 깊이와 바로 위 부모 노드가 구해짐
    visit.resize(n+1);
    D.resize(n+1);
    
    // LCA 배열의 행 개수 K 구하기
    k=0;
    int temp=1;
    while(temp<=n){
        temp*=2;
        k++;
    }

    BFS(1);

    for(int i=1;i<k+1;i++){
        for(int j=1;j<n+1;j++){
            LCA[i][j]=LCA[i-1][LCA[i-1][j]];
        }
    }

    
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        
        int res = LCAFunc(a,b);
        cout << res << "\n";
    }
}


void BFS(int s){
    queue<int> q1;
    visit[s]=true;
    q1.push(s);
    
    int depth=0;
    int cnt=0;
    int size=1;

    LCA[0][s]=0;
    D[s]=depth++;
    

    while(!q1.empty()){
        int now = q1.front();
        q1.pop();

        for(int i : Tree[now]){
            if(!visit[i]){
                q1.push(i);
                visit[i]=true;

                // 이후 자식 노드들은 탐색 단계마다 깊이를 1씩 추가
                // 현재 선택된 노드의 인접 노드중 방문하지 않은, 즉 자식 노드
                LCA[0][i]=now;
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

int LCAFunc(int a,int b){
    // 깊이가 다른 경우 높이 맞추고 진행해야함
    // 구현상의 용이함을 위해 깊이가 더 작은 노드를 a에 둬서 맞춤
    if(D[a]>D[b]){
        int tmp=a;
        a=b;
        b=tmp;
    }

    // D[a]>D[b]
    // 둘이 같아질 때까지 a를 위로 이동시키기
    for(int i=k;i>-1;i--){
        if(pow(2,i)<=D[b]-D[a]){
            if(D[a]<=D[LCA[i][b]]){
                b=LCA[i][b];
            }
        }
    }


    // 깊이가 같으면 각 단계에서 두 노드를 부모 노드로 이동
    // 같은 노드로 이동될 때까지 반복
    for(int i=k;i>-1 && a!=b ;i--){
        if(LCA[i][a] != LCA[i][b]){
            a=LCA[i][a];
            b=LCA[i][b];
        }
    }

    int res = a;
    if(a!=b){
        res=LCA[0][res];
    }

    return res;
}