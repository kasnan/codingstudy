#include<iostream>
#include<memory.h>

using namespace std;

int n,m;
int A[50][50];
int dist[50][50];

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

int ans=0;

void Solution(){

}

void Solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==2){

            }
        }
    }


}

void Input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }
    Solve();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Input();
}