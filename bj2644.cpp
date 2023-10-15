#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> A;

int main(){
    int N;
    cin >> N;

    A.resize(N+1);

    int p1,p2;
    cin >> p1 >> p2;

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        A[x].push_back(y);
    }
}