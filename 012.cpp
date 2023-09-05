#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N,0);
    vector<int> ans(N,0);

    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    stack<int> s1;
    s1.push(0);

    for(int i=0;i<N;i++){
        // stack top value가 현재 입력값보다 작은동안
        // 빌 때까지 반복이 핵심
        // 새로 입력되는 값이 더 작은 경우 push 후 다음으로

        // 그 다음 입력값이 그 이전의 값보다도 크면 오큰수가 되는 것
        // 마지막까지 못하면 스택에 남아있게 된다.
        while(!s1.empty() && A[i] > A[s1.top()]){
            ans[s1.top()] = A[i];
            s1.pop();
        }
        s1.push(i);
    }

    // 스택이 빌 때까지 pop해서 -1넣기
    // 위 과정이 끝나고 남은 원소를 인덱스로 하는 원소는 오큰수 X
    while(!s1.empty()){
        ans[s1.top()]=-1;
        s1.pop();
    }

    for(int i=0;i<N;i++){
        cout << ans[i] << ' ';
    }
}