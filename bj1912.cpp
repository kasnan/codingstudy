#include<iostream>

using namespace std;

int A[100001];
int D[100001];
int main(){
    int n;
    cin >> n;

    for(int i=1;i<n+1;i++){
        cin >> A[i];
    }
    
    D[1]=A[1];
    int maxval=D[1];
    for(int i=2;i<n+1;i++){
        D[i]=max(A[i],D[i-1]+A[i]);
        maxval=max(D[i],maxval);
    }

    cout << maxval;

}