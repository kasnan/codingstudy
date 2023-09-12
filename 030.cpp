#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> L(N);
    for(int i=0;i<N;i++){
        cin >> L[i];
    }

    // 각 레슨의 길이는 10000이하
    // M개의 블루레이에 맞게 들어가도록 블루레이의 최소 크기를 지정
    sort(L.begin(),L.end());
    int s = L[N-1];
    int e = 0;
    for(int i=0;i<N;i++){
        e+=L[i];
    }

    // 이진 탐색을 하면서 시작 인덱스가 끝 인덱스보다 커지면
    // 그 이전에 s=e이고 mid=s이다.
    // 이 때 count가 M을 초과해 좀 더 큰 크기가 필요한 조건에 걸려 s=mid+1
    // 그러면서 s>e되면서 while문 탈
    
    while(s<=e){
        int mid = (s+e)/2;
        // sum변수는 레슨 길이를 합쳐서 크기를 비교하기 위함
        // count변수는 저장하면서 총 몇 장의 블루레이를 사용하는 지 확인하기 위함    
        int sum=0,count=0;

        // mid로 정해진 블루레이의 크기에 합치면서 비교
        for(int i=0;i<N;i++){

            // 현재까지의 크기 합이 mid보다 크면 크기가 부족
            if(sum + L[i] > mid){
                // 새로운 블루레이로 교체
                sum=0;
                count++;
            }
            sum+=L[i];
        }
        // 맞춰서 저장이 이루어졌으면 sum은 0으로 초기화돼고 루프문이 종료
        // 0이 아니면 새로운 블루레이 한장에 저장
        if(sum!=0){
            count++;
        }
        // 현재의 크기로 정해진 최대 장수 M을 초과했으니 좀 더 큰 크기로 탐색
        if(count > M){
            s=mid+1;
        }
        // 현재 크기로 충분히 M장보다 넉넉하게 저장가능하므로 좀 더 작은 크기로 탐색
        else{
            e=mid-1;
        }
    }
    cout << s << endl;
}