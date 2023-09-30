#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long D[N+1];
    D[1]=0;
    D[2]=1;
    for(int i=3;i<N+1;i++){
        D[i]=(long long)((i-1)*(D[i-1]+D[i-2])) % 1000000000;
    }
    cout << D[N];
}