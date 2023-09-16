#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;


    int res=2;
    for(int i=1;i<N+1;i++){
        res=2*res-1;
    }
    res=res*res;

    cout << res << endl;
}