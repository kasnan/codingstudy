#include<iostream>

using namespace std;

int D[1000001];

int main(){
    int N;
    cin >> N;

    D[1]=1;
    D[2]=2;
    for(int i=3;i<N+1;i++){
        D[i]=(D[i-1]+D[i-2])%15746;
    }
    cout << D[N];
}