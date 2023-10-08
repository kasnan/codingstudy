#include<iostream>

using namespace std;

int D[1000][1000];

int main(){
    int n,m;
    cin >> n >> m;

    int max=0;
    for(int i=0;i<n;i++){
        string line;
        cin >> line;
        for(int j=0;j<m;j++){
            D[i][j]=line[j]-'0';
            if(D[i][j]==1 && i>0 && j>0){
                D[i][j]=min(D[i-1][j-1],min(D[i][j-1],D[i-1][j]))+1;
            }
            if(max<D[i][j]){
                max=D[i][j];
            }
        }
    }
    cout << max * max << endl;
}