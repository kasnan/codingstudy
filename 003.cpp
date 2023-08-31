#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N,M;
    vector<int> v1;
    v1.push_back(0);
    int sum=0;

    cin >> N >> M;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        sum+=tmp;
        v1.push_back(sum);
    }
    for(int i=0;i<M;i++){
        sum=0;
        int start,end;
        cin >> start >> end;
        sum=v1[end]-v1[start-1];

        cout << sum << endl;
    }
}