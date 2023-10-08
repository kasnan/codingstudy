#include<iostream>

using namespace std;

long D[101][101][101];
long mod=1000000007;

int main(){
    int N,L,R;
    cin >> N >> L >> R;
    D[1][1][1]=1;
    for(int i=2;i<N+1;i++){
        for(int j=1;j<L+1;j++){
            for(int k=1;k<R+1;k++){
                D[i][j][k]=(D[i-1][j-1][k]+D[i-1][j][k-1]+(i-2)*D[i-1][j][k])%mod;
            }
        }
    }

    cout << D[N][L][R] << endl;

}