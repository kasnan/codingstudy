#include<iostream>

using namespace std;

int D[101][101];

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> D[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][k]==1 &&D[k][j]==1){
                    D[i][j]=1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }
}