#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    long min,max;
    cin >> min >> max;

    vector<bool>ch(max-min+1,false);
    int cnt=0;

    // max 이하의 제곱수의 배수를 체크한다.
    for(long i=2;pow(i,2)<max+1;i++){
        long pown = pow(i,2);
        long start = min/pown;

        // min보다 크거나 같은 제곱수의 배수부터 시작하기 위함.
        if(min%pown!=0){
            start++;
        }


        for(long j = start;j*pown<max+1;j++){
            ch[j*pown-min]=true;
        }
    }

    // 제곱수로 체크되지 않은 범위 내 수를 모두 체크한다.
    for(int i=0;i<max-min+1;i++){
        if(!ch[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
}