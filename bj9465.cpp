#include<iostream>
#define MAX 100000
using namespace std;

int n;


int main(){
    int T;
    cin >> T;

    int A[2][MAX];
    int D[MAX][3];

    for(int t=0;t<T;t++){
        cin >> n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> A[i][j];
            }
        }

        D[0][0]=A[0][0];
        D[0][1]=A[0][1];
        D[0][2]=0;

        for(int i=1;i<n;i++){
            D[i][0]=A[i][0]+max(D[i-1][1],D[i-1][2]);
            D[i][1]=A[i][1]+max(D[i-1][0],D[i-1][2]);
            D[i][2]=max(D[i-1][0],D[i-1][1]);
        }

        int maxV=0;
        for(int i=0;i<3;i++){
            maxV=max(maxV,D[n-1][i]);
        }

        cout << maxV << "\n";

    }
}