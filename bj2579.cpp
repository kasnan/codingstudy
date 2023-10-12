#include<iostream>

using namespace std;

int A[301];
int D[301];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<n+1;i++){
        cin >> A[i];
    }

    D[0]=0;
    D[1]=A[1];
    D[2]=A[2]+A[1];

    for(int i=3;i<n+1;i++){
        D[i]=A[i]+max(D[i-2],D[i-3]+A[i-1]);
    }

    cout << D[n];

}