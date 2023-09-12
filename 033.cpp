#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// 구조체 안에 bool형 연산 함수 작성하기
struct cmp {
  bool operator()(int a, int b) {
    return a > b;
  }
};

int main(){
    int N;
    cin >> N;

    // vector<int>A(N+1,0);
    priority_queue<int,vector<int>,greater<int>> pq1;
    // priority_queue<int,vector<int>,cmp> pq1;

    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        pq1.push(tmp);
    }
    int sum=0;
    int data1=0,data2=0;
    // sort(A.begin(),A.end()-1);
    // for(int i=1;i<N;i++){
    //     A[i]=A[i-1]+A[i];
    // }
    // A[N]=A[N-1]+A[N-2];
    // cout << A[N] << endl;

    while(pq1.size()>1){
        data1 = pq1.top();
        pq1.pop();
        data2 = pq1.top();
        pq1.pop();
        sum+=(data1+data2);
        pq1.push(data1+data2);
    }

    cout << sum << endl;
}