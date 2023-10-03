#include<iostream>

using namespace std;

long D[91][2];

int main(){
    int N;
    cin >> N;

    D[1][1]=1;
    D[1][0]=0;
    
    for(int i=2;i<N+1;i++){
        D[i][0]=D[i-1][0]+D[i-1][1];
        D[i][1]=D[i-1][0];
    }

    cout << D[N][1]+D[N][0] << endl;

}