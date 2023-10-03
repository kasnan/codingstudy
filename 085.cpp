#include<iostream>

using namespace std;

int T[16];
int P[16];
int D[16]={0, };


int main(){
    int N;
    cin >> N;

    for(int i=1;i<N+1;i++){
        cin >> T[i] >> P[i];
    }

    for(int i=N;i>0;i--){
        if(T[i]+i>N+1){
            D[i]=D[i+1];
        }
        else{
            D[i]=max(D[i+1],D[i+T[i]]+P[i]);
        }
    }


    cout << D[1] << endl;

}