#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;

vector<int> tree[MAX+1];
bool visit[MAX+1]={false, };
int ans[MAX+1]={-1, };

void DFS(int s);

int main(){
    int n;
    cin >> n;

    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);

    for(int i=2;i<n+1;i++){
        cout << ans[i] << "\n";
    }
}

void DFS(int s){
    visit[s] = true;

    for(int i=0;i<tree[s].size();i++){
        int next = tree[s][i];
        if(!visit[next]){
            ans[next]=s;
            DFS(next);
        }
    }
}