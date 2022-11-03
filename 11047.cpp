#include<iostream>
using namespace std;


int get_limit(int *arr,int k){
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        if(arr[i]>=k)
            return i-1;
    }
}

void compute(int *arr,int k){
    int limit=get_limit(arr,k);
    int cnt=0;


}

int main(){
    int N,K;
    int valuearr[10];
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> valuearr[i];
    }
    compute(valuearr,K);
}