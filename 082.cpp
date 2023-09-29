#include<iostream>

using namespace std;

long D[202][202];

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    for(int i=0;i<201;i++){
        for(int j=0;j<i+1;j++){
            if(j==i || j==0){
                D[i][j]=1;
            }
            else{
                D[i][j]=D[i-1][j]+D[i-1][j-1];
                if(D[i][j]>1000000000){
                    D[i][j]=1000000001;
                }
            }
        }
    }

    if(D[n+m][m]<k){
        cout << -1;
    }
    else{
        while(!(n==0 && m==0)){
            if(D[n+m-1][m] >= k){
                cout << "a";
                n--;
            }
            else{
                cout << "z";
                k=k-D[n+m-1][m];
                m--;
            }
        }
    }

}