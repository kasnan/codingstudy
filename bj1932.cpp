#include<iostream>

using namespace std;

int A[501][501];
int D[501][501];

int main(){
    int n;
    cin >> n;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            cin >> A[i][j];
        }
    }

    D[1][1]=A[1][1];
    D[2][1]=D[1][1]+A[2][1];
    D[2][2]=D[1][1]+A[2][2];

    for(int i=3;i<n+1;i++){
        D[i][1]=D[i-1][1]+A[i][1];
        for(int j=2;j<i;j++){
            D[i][j]=max(D[i-1][j],D[i-1][j-1])+A[i][j];
        }
        D[i][i]=D[i-1][i-1]+A[i][i];
    }

    int maxval=D[n][1];
    for(int i=2;i<n+1;i++){
        maxval=max(maxval,D[n][i]);
    }

    cout << maxval;
}