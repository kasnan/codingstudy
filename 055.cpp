#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int,int>>> A;
vector<vector<pair<int,int>>> A_R;
vector<int> D;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> A;
    vector<vector<pair<int,int>>> A_R;
    vector<int> D;

    A.resize(n+1);
    A_R.resize(n+1);
    D=vector<int>(n+1,0);

    // 그래프 정보 저장(인접 리스트)
    for(int i=0;i<m;i++){
        int s,e,t;
        cin >> s >> e >> t;
        A[s].push_back(make_pair(e,t));
        D[e]++;
        // edge 뒤집기
        A_R[e].push_back(make_pair(s,t));
    }
    
    int startcity,endcity;
    cin >> startcity >> endcity;

    // 위상 정렬 수행
    // 수행 과정에서 해당 도시까지의 임계 경로 값을 구한다.
    queue<int> q1;
    q1.push(startcity);
    vector<int> result(n+1);

    while(!q1.empty()){
        int now = q1.front();
        q1.pop();

        for(pair<int,int> i : A[now]){
            D[i.first]--;
            // 해당 도시까지 최대한 오래 걸리는 시간을 구해야함
            // 그렇게 함으로써 최종적으로 다같이 도착지점까지 시간을 맞출 수 있으므로..
            result[i.first]=max(result[i.first],result[now]+i.second);
            if(D[i.first]==0){
                q1.push(i.first);
            }
        }
    }

    // edge를 뒤집어서 위상 정렬을 재수행
    // 현재 노드의 임계 경로가 인접 노드의 임계경로+인접노드에서 현재 노드까지 걸리는 시간의 값과 같으면
    // 모두 임계 경로 데이터에 맞춰 마지막 도시에서 동시에 만나야 하므로
    // 한 도시의 임계 경로+다음 도시까지의 소요 시간의 경우를 임계경로와
    // 비교해야 한다.
    int rescnt=0;
    vector<bool>visit(n+1,false);
    queue<int> rq1;
    rq1.push(endcity);
    visit[endcity]=true;

    while(!rq1.empty()){
        int now = rq1.front();
        rq1.pop();

        for(pair<int,int> i : A_R[now]){
            // 임계 경로에 딱 맞는 경우
            if(result[i.first]+i.second==result[now]){
                rescnt++;
                if(!visit[i.first]){
                    visit[i.first]=true;
                    rq1.push(i.first);
                }
            }
        }
    }
    // 마지막 도시의 임계 경로, 즉 최종적으로 모두가 맞춰야 하는 시간
    cout << result[endcity] << endl;
    // 연결된 도시 간 임계경로를 비교하면서 임계경로와 시간이 맞춰지는 경우
    cout << rescnt << endl;

}