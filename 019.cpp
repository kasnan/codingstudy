#include<iostream>
#include<vector>

using namespace std;

void swapnums(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int>&A,int start,int end){
    // 정렬할 데이터 묶음의 크기가 2이면 그대로 정렬하고 종료
    if(start+1==end){
        if(A[start]>A[end]){
            swapnums(&A[start],&A[end]);
        }
        return end;
    }

    // 중간 위치 데이터를 제일 왼쪽 끝 데이터와 swap
    int M = (start+end)/2;
    swapnums(&A[start],&A[M]);

    // pivot을 제일 왼쪽 데이터로 지정
    int pivot = A[start];
    int i=start+1,j=end;

    // pivot과 비교하면서 두 포인터의 이동
    while(i<j){
        while(pivot < A[j] && j > 0){
            j--;
        }
        while(pivot > A[i] && i < A.size() - 1){
            i++;
        }
        // pivot과 크기가 맞지 않고 범위에서 벗어나지 않으면
        // 왼쪽 포인터와 오른쪽 포인터의 데이터를 swap
        if(i<=j){
            swapnums(&A[i],&A[j]);
            i++;
            j--;
        }
    }

    // pivot과 멈춘 j위치의 데이터를 swap
    A[start]=A[j];
    A[j]=pivot;

    // 정렬 과정이 한번 종료 되면 pivot은 맞는 위치에 위치된다.
    return j;
}

void quicksort(vector<int>&A,int start,int end,int k){
    int pivot = partition(A,start,end);
    if(pivot == k){
        return;
    }
    else if(k<pivot){
        quicksort(A,start,pivot-1,k);
    }
    else{
        quicksort(A,pivot+1,end,k);
    }
}


int main(){

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    quicksort(A,0,N-1,K);
    cout << A[K-1];    
}

