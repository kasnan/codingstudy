#include<iostream>

using namespace std;

int n;
int A[100][100];
long D[100][100];

void Solve();
void Solution();
int DFS(int y,int x);

int main(){
    
    Solve();
}

void Solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }
    D[0][0]=1;
    Solution();
}

void Solution(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(D[i][j]==0 || A[i][j]==0) continue;

            int dist=A[i][j];
            int Down=i+dist;
            int Right=j+dist;

            if(Down<n)  D[Down][j]+=D[i][j];
            if(Right<n) D[i][Right]+=D[i][j];    
        }
    }
    cout << D[n-1][n-1];
}


