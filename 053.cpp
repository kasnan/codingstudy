#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> A;
vector<int> D;
queue<int> T;
vector<bool> visit;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    // 초기 그래프 정보 및 진입 차수 저장
    A.resize(n+1);
    D=vector<int>(n+1,0);
    visit=vector<bool>(n+1,false);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
        D[b]++;
    }

    for(int i=1;i<n+1;i++){
        if(D[i]==0){
            T.push(i);
        }
    }

    while(!T.empty()){
        int now=T.front();
        T.pop();
        cout << now << " ";
        // 선택된 노드가 가리키는 모든 노드의 진입 차수 1 감소
        for(int i : A[now]){
            D[i]--;
            if(D[i]==0 && !visit[i]){
                T.push(i);
                visit[i]=true;
            }
        }
    }
}