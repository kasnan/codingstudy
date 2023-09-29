#include<iostream>

using namespace std;

int D[15][15];

int main(){
    int T;
    cin >> T;

    // 0층 i호에는 i명이 산다.
    for(int i=1;i<15;i++){
        D[0][i]=i;
        D[i][1]=1;
    }

    for(int i=1;i<15;i++){
        for(int j=2;j<15;j++){
            D[i][j]=D[i][j-1]+D[i-1][j];
        }
    }


    for(int i=0;i<T;i++){
        int k,n;
        cin >> k >> n;
        cout << D[k][n] << endl;
    }
}