#include<iostream>
#include<vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visit;
static vector<int> grp;
static bool isEven;

void DFS(int n);

int main(){
    int k;
    cin >> k;

    for(int i=0;i<k;i++){
        int v,e;
        cin >> v >> e;
        A.resize(v+1);
        visit.resize(v+1);
        grp.resize(v+1);
        isEven=true;

        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            A[a].push_back(b);
            A[b].push_back(a);
        }

        for(int i=1;i<v+1;i++){
            if(isEven){
                DFS(i);
            }
            else{
                break;
            }

        }

        if(isEven){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

        for(int i=0;i<v+1;i++){
            A[i].clear();
            visit[i]=false;
            grp[i]=0;
        }
    }
}

void DFS(int n){
    visit[n]=true;

    for(int i : A[n]){
        if(!visit[i]){
            // 이분 그래프는 노드들을 두 집합으로 분할 즉 그룹을 둘로 하면 된다.
            // 인접 노드중 방문하지 않은 노드는 바로 다른 집합으로 두면 된다.
            grp[i]=(grp[n]+1)%2;
            DFS(i);
        }
        else if(grp[i]==grp[n]){
            // 인접 노드인데 방문한 노드인 경우 해당 노드의 그룹을 확인한다.
            // 만약 같은 그룹이 되는 경우 노드들을 두 집합으로 나눌 수 없게 된다.
            isEven=false;
        }
    }
}