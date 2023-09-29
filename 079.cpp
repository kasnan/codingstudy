#include<iostream>

using namespace std;

int D[31][31];

int main(){
    int T;
    cin >> T;

    for(int i=0;i<31;i++){
        D[i][0]=1;
        D[i][i]=1;
        D[i][1]=i;
    }

    for(int i=2;i<31;i++){
        for(int j=1;j<i+1;j++){
            D[i][j]=D[i-1][j]+D[i-1][j-1];
        }
    }

    for(int i=0;i<T;i++){
        int n,m;
        cin >> n >> m;
        cout << D[m][n] << endl;
    }

}