#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> A;
vector<bool> visit;
vector<int> grp;
bool isEven;

void DFS(int n);

int main(){
    int k;
    cin >> k;

    for(int i=0;i<k;i++){
        int v,e;
        cin >> v >> e;
        A.resize(v+1);
        visit=vector<bool>(v+1,false);
        grp=vector<int>(v+1);
        isEven=true;

        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            A[a].push_back(b);
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
            grp[i]=(grp[n]+1)%2;
            DFS(i);
        }
        else if(grp[i]==grp[n]){
            isEven=false;
        }
    }
}