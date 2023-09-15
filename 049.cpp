#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> node;

vector<vector<bool>> visit;
vector<bool> ans;
vector<int> bucket(3);

void BFS();

int main(){
    // 각 물통의 용량을 입력
    for(int i=0;i<3;i++){
        cin >> bucket[i];
    }

    // 이전에 있었던 상태인지 확인
    // 물 양에 대해 두 통만 알면 나머지 한통도 확인 가능하므로 두 통만 저장
    visit.resize(201);
    for(int i=0;i<201;i++){
        visit[i]=vector<bool>(201,false);
    }

    // 조건에 맞는 C의 용량만 확인하면 되므로 해당 용량이면 true로 함
    ans=vector<bool>(201,false);
    BFS();

    for(int i=0;i<ans.size();i++){
        if(ans[i]){
            cout << i << " ";
        }
    }

}

static int S[6]={0,0,1,1,2,2};
static int R[6]={1,2,0,2,0,1};

void BFS(){
    queue<node> q1;
    q1.push(node(0,0));
    visit[0][0]=true;
    ans[bucket[2]]=true;

    while(!q1.empty()){
        node now = q1.front();
        q1.pop();
        for(int i=0;i<6;i++){
            // a,b,c에 대한 현재 상태를 불러온다.
            int next[3]={now.first,now.second,bucket[2]-now.first-now.second};
            
            // 물을 옮기는 행동은 총 6종류
            // a-> b or c, b-> a or c, c-> a or b
            
            // 물을 받는 쪽으로 전부 옮기기
            next[R[i]]+=next[S[i]];
            next[S[i]]=0;

            // 용량이 넘치는 경우 해당 양만큼 빼서 다시 보내는 쪽으로 옮기기
            if(next[R[i]]>bucket[R[i]]){
                next[S[i]]=next[R[i]]-bucket[R[i]];
                next[R[i]]=bucket[R[i]];
            }

            // 물을 옮긴 후의 상태가 이전에 찾아본 상태가 아닌 지 확인
            if(!visit[next[0]][next[1]]){
                visit[next[0]][next[1]]=true;
                q1.push(node(next[0],next[1]));

                // 이 때, a 물통이 비어있는 경우에 c 물통의 물 양의 상태를 저장
                if(next[0]==0){
                    ans[next[2]]=true;
                }
            }
        }
    }
}