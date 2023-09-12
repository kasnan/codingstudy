#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,K;
    cin >> N;

    cin >> K;

    vector<vector<int>>A;
    A.resize(N+1);

    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            A[i].push_back(i*j);
        }
    }

    vector<int>B(N+1);



    cout << B[k] << endl;
}