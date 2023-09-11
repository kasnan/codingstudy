#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int,int> Node;
static vector<vector<Node>> A;
static vector<bool> visit;
static vector<int> ch;

void BFS(int s);

int main(){
    int V;
    cin >> V;
    A.resize(V+1);
    
    // 트리 정보 저장
    // 인접 노드와 함께 거리를 저장
    for(int i=0;i<V;i++){
        int S;
        cin >> S;
        while(true){
            int node,dist;
            cin >> node;
            if(node == -1){
                break;
            }
            cin >> dist;
            Node n = make_pair(node,dist);
            A[S].push_back(n);
        }
    }

    ch = vector<int>(V+1,0);
    visit = vector<bool>(V+1,false);

    BFS(1);

    int max=1;

    for(int i=2;i<V+1;i++){
        if(ch[max]<ch[i]){
            max=i;
        }
    }

    fill(ch.begin(),ch.end(),0);
    fill(visit.begin(),visit.end(),false);

    BFS(max);
    sort(ch.begin(),ch.end());
    cout << ch[V] << endl;
}

void BFS(int s){
    queue<int> q1;
    q1.push(s);
    visit[s]=true;

    while(!q1.empty()){
        int fr = q1.front();
        q1.pop();

        for(Node i : A[fr]){
            if(visit[i.first] == false){
                visit[i.first]=true;
                q1.push(i.first);
                ch[i.first]=i.second+ch[fr];
            }
        }

    }

}