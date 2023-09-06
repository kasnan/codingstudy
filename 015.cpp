#include<iostream>
#include<vector>

using namespace std;

void swapnums(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int N;
    cin >> N;

    int i,j;
    // 데이터 입력
    vector<int> A(N,0);
    for(i=0;i<N;i++){
        cin >> A[i];
    }

    // 데이터 정렬(버블 정렬)
    // 한번 사이클 돌면 가장 마지막 데이터 요소는 정렬된 요소
    
    j=N-1;
    while(j>0){
        for(i=0;i<j;i++){
            if(A[i]>A[i+1]){
                swapnums(&A[i],&A[i+1]);
            }
        }
        j--;
    }

    for(i=0;i<N;i++){
        cout << A[i] << endl;
    }
}