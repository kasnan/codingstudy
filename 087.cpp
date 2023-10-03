#include<iostream>

using namespace std;

long D[1001];

int main(){
    int N;
    cin >> N;
    D[1]=1;
    D[2]=2;
    for(int i=3;i<N+1;i++){
        D[i]=D[i-1]+D[i-2];
        D[i]%=10007;
    }

    cout << D[N] << endl;
}