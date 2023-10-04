#include<iostream>
#include<vector>

using namespace std;

long A[100000];
vector<long> L;
vector<long> R;

int main(){
    int n;
    cin >> n;
    
    L.resize(n);
    R.resize(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    L[0]=A[0];
    long result=L[0];
    for(int i=1;i<n;i++){
        L[i]=max(A[i],L[i-1]+A[i]);
        result=max(result,L[i]);
    }

    R[n-1]=A[n-1];
    for(int i=n-2;i>-1;i--){
        R[i]=max(A[i],R[i+1]+A[i]);
    }

    for(int i=1;i<n-1;i++){
        result=max(result,L[i-1]+R[i+1]);
    }

    cout << result << endl;

    
}