#include<iostream>

using namespace std;

long D[101][11];

int main(){
    int N;
    cin >> N;

    D[1][0]=0;
    for(int i=1;i<10;i++){
        D[1][i]=1;
    }

    for(int i=2;i<N+1;i++){
        D[i][0]=D[i-1][1];
        D[i][9]=D[i-1][8];
        for(int j=1;j<9;j++){
            D[i][j]=(D[i-1][j+1]+D[i-1][j-1])%1000000000;
        }
    }

    long sum=0;
    for(int j=0;j<10;j++){
        sum=(sum+D[N][j])%1000000000;
    }

    cout << sum << endl;
}