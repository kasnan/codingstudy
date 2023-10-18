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
    
    for(int i=0;i<k+1;i++){
        D[i]=10001;
    }
    D[0]=0;

    for(int i=0;i<n;i++){
        for(int j=C[i];j<k+1;j++){
            D[j]=min(D[j],D[j-C[i]]+1);
        }
    }

    if(D[k]==10001){
        cout << -1;
    }
    else{
        cout << D[k];
    }


    
}