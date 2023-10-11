#include<iostream>

using namespace std;

int A[301];
int D[301][2];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<n+1;i++){
        cin >> A[i];
    }

    D[1][0]=D[1][1]=A[1];
    D[2][0]=A[2];
    D[2][1]=A[2]+A[1];

    for(int i=3;i<n+1;i++){
        D[i][0]=A[i]+D[i-2][1];
        D[i][1]=A[i]+D[i-1][0];
    }

    int res=max(D[n][0],D[n][1]);
    cout << res;

}