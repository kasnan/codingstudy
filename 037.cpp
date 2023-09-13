#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int M,N;
    cin >> M >> N;

    vector<int>P(N+1,0);
    for(int i=1;i<N+1;i++){
        P[i]=i;
    }
    P[1]=0;
    for(int i=2;i<sqrt(N)+1;i++){
        if(P[i]>0){
            for(int j=i+1;j<N+1;j++){
                if(j%i==0){
                    P[j]=0;
                }
            }
        }
    }

    for(int i=M;i<N+1;i++){
        if(P[i]>0){
            cout << i << endl;
        }
    }
    
}