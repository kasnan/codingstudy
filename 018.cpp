#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> P(N);

    for(int i=0;i<N;i++){
        cin >> P[i];
    }


    // 데이터는 1번째부터 정렬 대상으로 해서 루프
    int insert_point;
    int insert_value;
    for(int i=1;i<N;i++){
        insert_point=i;
        insert_value=P[i];

        // 정렬 범위는 정렬하기로 선택한 처음(0번째부터) 데이터 위치까지 진행
        // 정렬할 위치 찾기
        for(int j=i-1;j>-1;j--){
            if(P[i]>P[j]){
                insert_point=j+1;
                break;
            }
            if(j==0){
                insert_point=0;
            }
        }
        
        
        // 정렬할 위치에 삽입하기
        for(int j=i;j>insert_point;j--){
            P[j]=P[j-1];
        }
        P[insert_point]=insert_value;

        // P.erase(P.begin()+insert_point+1);
        // P.insert(P.begin()+insert_point,insert_value);
    }


    vector<int> S(N);
    S[0]=P[0];
    for(int i=1;i<N;i++){
        S[i]=S[i-1]+P[i];
    }

    int sum=0;
    for(int i=0;i<N;i++){
        sum+=S[i];
    }
    cout << sum;
}