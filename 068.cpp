#include<iostream>
#include<vector>
#define MAX 50
using namespace std;

vector<int> tree[MAX];
bool visit[MAX]={false, };
int cnt=0;
int del;

void DFS(int n);

int main(){
    int n,root;
    cin >> n;

    for(int i=0;i<n;i++){
        int node;
        cin >> node;
        if(node!=-1){
            tree[i].push_back(node);
            tree[node].push_back(i);
        }
        else{
            root=i;
        }
        
    }

    cin >> del;
    if(del!=root){
        DFS(root);
        cout << cnt << endl;
    }
    else{
        cout << 0 << endl;
    }
    

}

void DFS(int n){
    visit[n]=true;
    int childn=0;

    for(int i : tree[n]){
        if(!visit[i] && i != del){
            childn++;
            DFS(i);
        }
    }
    if(childn==0){
        cnt++;
    }
}