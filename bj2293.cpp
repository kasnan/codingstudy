#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
int C[100];
int D[10001];

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> C[i];
    }
    sort(&C[0],&C[n-1]);
    D[0]=0;

    for(int i=0;i<n;i++){
        for(int j=C[i];j<k+1;j++){
            D[j]+=D[j-C[i]];
        }
    }
    cout << D[k];
}