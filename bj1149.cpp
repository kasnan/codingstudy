#include<iostream>

using namespace std;


int A[1001][3];
int D[1001][3];

int exec(int idx,int c1,int c2);

int main(){
    int N;
    cin >> N;
    for(int i=1;i<N+1;i++){
        for(int j=0;j<3;j++){
            cin >> A[i][j];
        }
    }
    D[1][0]=A[1][0];
    D[1][1]=A[1][1];
    D[1][2]=A[1][2];

    for(int i=2;i<N+1;i++){
        D[i][0]=exec(i,1,2);
        D[i][1]=exec(i,2,0);
        D[i][2]=exec(i,0,1);
    }

    int res = min(D[N][0],min(D[N][1],D[N][2]));

    cout << res;
}

int exec(int idx,int c1,int c2){
    idx-=1;
    if(D[idx][c1]>D[idx][c2]){
        return D[idx][c2]+A[idx+1][(c2+1)%3];
    }
    return D[idx][c1]+A[idx+1][(c2+1)%3];
}