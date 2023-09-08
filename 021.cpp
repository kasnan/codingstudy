#include<iostream>
#include<vector>

using namespace std;

static vector<int> A;
static vector<int> tmp;
static long result;

void mergesort(int s,int e){
    if(e-s<1){
        return;
    }

    // 중간 지점을 나눠 분할해 재귀 호출
    // 최소 단위는 위 조건문에서 걸러진다.
    int m = s+ (e-s)/2;
    mergesort(s,m);
    mergesort(m+1,e);

    // 분할된 부분의 데이터는 tmp에 복사된다.
    for(int i=s;i<=e;i++){
        tmp[i]=A[i];
    }

    // 반으로 나눠 정렬을 진행
    int k=s;
    int index1=s;
    int index2=m+1;

    // index1은 중간지점까지, index2는 끝까지
    // 중간을 나눠 더 작은 값을 원본 데이터에 입력
    while(index1<=m&&index2<=e){
        if(tmp[index1]>tmp[index2]){
            A[k]=tmp[index2];
            result+=(index2-k);
            k++;
            index2++;
        }
        else{
            A[k]=tmp[index1];
            k++;
            index1++;
        }
    }

    // index들이 덜 진행되어서 남아있는 값을 그대로 입력
    while(index1<=m){
        A[k] = tmp[index1];
        k++;
        index1++;
    }
    while(index2<=e){
        A[k] = tmp[index2];
        k++;
        index2++;
    }
}


int main(){
    int N;
    cin >> N;
    result = 0;
    A = vector<int>(N+1);
    tmp = vector<int>(N+1);
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    
    mergesort(1,N);

    cout << result;

}