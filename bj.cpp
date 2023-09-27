#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> A;
vector<bool> visit;

void DFS(int start);
void BFS(int start);

int main(){
    int n,e,s;
    cin >> n >> e >> s;

    A.resize(n+1);

    // 인접 리스트로 구현
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    visit.resize(n+1);
    fill(visit.begin(),visit.end(),false);

    DFS(s);
    cout << "\n";
    fill(visit.begin(),visit.end(),false);

    BFS(s);
}

void DFS(int s){
    visit[s]=true;
    cout << s << " ";
    for(int i : A[s]){
        if(!visit[i]){
            DFS(i);
        }
    }
}

void BFS(int s){
    queue<int> q1;

    visit[s]=true;
    q1.push(s);

    while(!q1.empty()){
        int now = q1.front();
        q1.pop();

        cout << now << " ";

        for(int i : A[s]){
            if(!visit[i]){
                q1.push(i);
                visit[i]=true;
            }
        }
    }
    

}