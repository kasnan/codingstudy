#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swapnums(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

typedef pair<int,int> Node;

int main(){
    int N;
    cin >> N;


    // change라는 부울형 변수를 통해 정렬이 이뤄지지 않은 위치를 알아내는 알고리즘
    // 버블 정렬로 수열을 오름차순으로 정렬할 때 다음 요소와 비교할 때 다음 요소가 더 큰 경우
    // 두 요소가 swap되지 않는다.

    vector<Node> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i].first;
        A[i].second=i;
    }
    sort(A.begin(),A.end());
    int max=0;

    for(int i=0;i<N;i++){
        if(max < A[i].second - i){
            max = A[i].second - i;
        }
    }

    cout << max + 1;

    // bool change = false;
    // for(int i=1;i<=N+1;i++){
    //     change = false;
    //     for(int j=1;j<=N-i;j++){
    //         if(A[j] > A[j+1]){
    //             change = true;
    //             swapnums(&A[j],&A[j+1]);
    //         }
    //     }
    //     if(change==false){
    //         cout << i << endl;
    //         break;
    //     }
    // }


}