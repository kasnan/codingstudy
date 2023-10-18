#include<iostream>
#include<queue>
#include<memory.h>

using namespace std;

pair<int,int> A[102];
bool visit[102];
int T,N;
int beer=20;

void BFS(int idx);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    // 처음에 맥주 20병
    // 50미터를 가기 전에 1병씩
    // 보충 없이 최대 1000m를 이동 가능
    for(int t=0;t<T;t++){
        // 편의점 개수=n
        cin >> N;
        for(int i=0;i<N+2;i++){
            // 집 좌표 1개, 편의점 좌표 n개, 페스티벌 좌표 1개
            cin >> A[i].first >> A[i].second;
        }
        BFS(0);
        if(!visit[N+1]){
            cout << "sad";
        }
        else{
            cout << "happy";
        }
        cout << "\n";
        memset(visit,false,sizeof(visit));
    }

}

void BFS(int idx){
    queue<int> q1;
    // visit[x][y]=true;
    q1.push(idx);
    visit[idx]=true;

    while(!q1.empty()){
        int cur=q1.front();
        q1.pop();

        // 두 지점 사이의 거리는 x좌표 차이 + y좌표 차이
        for(int i=1;i<N+2;i++){
            int dist=abs(A[cur].first-A[i].first)+abs(A[cur].second-A[i].second);
            if(!visit[i] && dist<=beer*50){
                visit[i]=true;
                q1.push(i);
            }
        }
    }
}