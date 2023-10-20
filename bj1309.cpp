#include<iostream>
#define MOD 9901;
using namespace std;

int A[100000][2];
int D[100000][3];
int n;

int main(){
    cin >> n;
    D[1][0]=1;
    D[1][1]=1;
    D[1][2]=1;

    for(int i=2;i<n+1;i++){
        D[i][0]=(D[i-1][1]+D[i-1][2])%MOD;
        D[i][1]=(D[i-1][0]+D[i-1][2])%MOD;
        D[i][2]=(D[i-1][0]+D[i-1][1]+D[i-1][2])%MOD;
    }
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=D[n][i];
    }
    cout << sum % MOD;
}