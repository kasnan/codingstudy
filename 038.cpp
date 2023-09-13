#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    long A,B;
    cin >> A >> B;

    // 최대 범위에서 소수를 구하기 2~10^7
    vector<long>P(10000001,0);
    for(int i=2;i<10000001;i++){
        P[i]=i;
    }

    for(int i=2;i<sqrt(10000001)+1;i++){
        if(P[i]>0){
            for(int j=i+i;j<10000001;j+=i){
                P[j]=0;
            }
        }
    }

    // 찾은 모든 소수에 대해 범위 내에 드는 거의 소수를 확인
    int cnt=0;
    for(int i=2;i<10000001;i++){
        if(P[i]>0){
            long temp = i;

            // 오버 플로우를 방지하기 위해 이항시켜 비교
            // temp에 계속해서 현재 소수를 곱한다.
            while(i <= (double)B/(double)temp){
                if(i>= (double)A/(double)temp){
                    cnt++;
                    temp*=i;
                }
            }
        }
    }
    
    cout << cnt << endl;
}