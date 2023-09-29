#include<iostream>

using namespace std;

int D[11][11];

int main(){
    int n,k;
    cin >> n >> k;

    // D[i][0]=1
    // D[i][1]=i
    // D[i][i]=1
    for(int i=0;i<n+1;i++){
        D[i][0]=1;
        D[i][1]=i;
        D[i][i]=1;
    }


    for(int i=2;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            D[i][j]=D[i-1][j]+D[i-1][j-1];
        }
    }

    cout << D[n][k] << endl;
}