#include<iostream>
#include<queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    // 수를 양수,음수,1,0으로 분류
    priority_queue<int,vector<int>,less<int>>plusq;
    priority_queue<int,vector<int>,greater<int>>minusq;
    int one=0;
    int zero=0;

    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp>1){
            plusq.push(tmp);
        }
        else if(tmp==1){
            one++;
        }
        else if(tmp==0){
            zero++;
        }
        else{
            minusq.push(tmp);
        }
    }
    int sum=0;
    while(plusq.size()>1){
        int data1,data2;
        data1 = plusq.top();
        plusq.pop();
        data2 = plusq.top();
        plusq.pop();

        sum+=(data1*data2);
    }
    if(!plusq.empty()){
        sum+=plusq.top();
        plusq.pop();
    }

    while(minusq.size()>1){
        int data1,data2;
        data1 = minusq.top();
        minusq.pop();
        data2 = minusq.top();
        minusq.pop();

        sum+=(data1*data2);
    }

    // 음수 큐 마지막 1개 데이터 처리하는 부분
    // zero가 1개라도 있었으면 그냥 0곱해서 없애고
    // zero가 1개도 없으면 그대로 pop해서 sum에 합한다.
    if(!minusq.empty() && zero==0){
        sum+=minusq.top();
        minusq.pop();
    }

    sum+=one;

    cout << sum << endl;
}