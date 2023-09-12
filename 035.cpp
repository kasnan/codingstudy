#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> meet;


int main(){
    int N;
    cin >> N;

    vector<meet>conf(N);

    // 종료시간 우선을 위해 종료 시간을 first로
    for(int i=0;i<N;i++){
        cin >> conf[i].second;
        cin >> conf[i].first;
    }

    // pair 자료형에 sort를 호출하면
    // first를 기준으로 정렬하고 first값이 같으면 second를 기준으로 정렬
    sort(conf.begin(),conf.end());

    int clr=1;
    meet now=conf[0];
    for(int i=0;i<N;i++){
        // 현재 진행되는 회의의 종료 시간이 다음 시작시간보다 작은 경우
        if(now.first<=conf[i].second){
            clr++;
            now=conf[i];
        }
    }

    cout << clr << endl;


}