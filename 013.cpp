#include<iostream>
#include<queue>
using namespace std;


int main(){
    int N;
    cin >> N;

    queue<int> A;
    for(int i=1;i<=N;i++){
        A.push(i);
    }

    while(A.size()>1){
        A.pop();
        int cnum = A.front();
        A.pop();
        A.push(cnum);
    }

    int ans = A.front();
    cout << ans;
}