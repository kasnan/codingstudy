#include<iostream>
#include<vector>

using namespace std;

void DFS(int v,int n);
bool isPrime(int inum);

vector<int> ans;
int N;

int main(){

    cin >> N;
    vector<int> start;
    start.push_back(2);    
    start.push_back(3);    
    start.push_back(5);    
    start.push_back(7);

    for(int i : start){
        DFS(i,1);
    }
    
    for(int i : ans){
        cout << i << endl;
    }
}

void DFS(int v, int n){
    if(n==N){
        if(isPrime(v)){
            ans.push_back(v);
        }
        return;
    }

    for(int i=1;i<10;i++){
        if(i%2!=0 &&  (v*10+i)){
            DFS(v*10+i,n+1);
        }
    }
}

bool isPrime(int inum){
    for(int i=2;i<inum/2+1;i++){
        if(inum%i==0){
            return false;
        }
    }
    return true;
}