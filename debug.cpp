#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

int main(){ // 배열에서 주어진 범위의 합을 구하세요!
    int testcase;
    cin >> testcase;

    int answer = 0;
    int A[100001] = {0};

    for(int i=1;i<10001;i++){
        A[i] = rand()*100;
    }

    for(int t=1;t<testcase + 1;t++){
        int start,end;
        cin >> start >> end;
        for(int i=start;i<=end;i++)
            answer+=A[i];
        cout << testcase << " " << answer << endl;
        // 각 testcase에서 주어진 범위의 배열 부분합 구해야하는데
        // answer가 이전 testcase의 값을 저장하는 문제가 있는 코드

        // answer를 0으로 다시 돌려야 함
        answer = 0;
    }
}