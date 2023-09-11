#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

typedef pair<int, int> Node;
static vector<vector<int>> A;
static vector<vector<bool>> ch;

static int N,M;

void BFS(Node start);

int main(){
    
    cin >> N >> M;

    A.resize(N);
    ch.resize(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ch[i].push_back(false);
        }
    }

    for(int i=0;i<N;i++){
        string col;
        cin >> col;
        for(int j=0;j<col.length();j++){
            A[i].push_back(col[j]-'0');
        }
    }

    // 시작 노드는 (0,0)
    // 도착 노드는 (N-1,M-1)
    Node start=make_pair(0,0);
    
    BFS(start);
    cout << A[N-1][M-1] << endl;

}

bool up(Node n){
    if(n.first-1 > 0 && A[n.first-1][n.second]!=0){
        return true;
    }
    return false;
}

bool down(Node n){
    if(n.first+1 < N && A[n.first+1][n.second]!=0){
        return true;
    }
    return false;
}

bool left(Node n){
    if(n.second-1 > 0 && A[n.first][n.second-1]!=0){
        return true;
    }
    return false;
}

bool right(Node n){
    if(n.second+1 <M && A[n.first][n.second+1]!=0){
        return true;
    }
    return false;
}

void BFS(Node start){
    queue<Node> q1;
    int cnt=0;

    q1.push(start);
    ch[start.first][start.second]=false;
    cnt++;

    //상하좌우 순서대로 스캔
    //방문했던 노드가 아니고 갈 수 있는 위치는 push
    while(!q1.empty()){
        Node front = q1.front();
        q1.pop();

        if(up(front) && !ch[front.first-1][front.second]){
            A[front.first-1][front.second]+=1;
            q1.push(make_pair(front.first-1,front.second));
            ch[front.first-1][front.second]=true;
        }
        if(down(front) && !ch[front.first+1][front.second]){
            A[front.first+1][front.second]+=1;
            q1.push(make_pair(front.first+1,front.second));
            ch[front.first+1][front.second]=true;
        }
        if(left(front) && !ch[front.first][front.second-1]){
            A[front.first][front.second-1]+=1;
            q1.push(make_pair(front.first,front.second-1));
            ch[front.first][front.second-1]=true;
        }
        if(right(front) && !ch[front.first][front.second+1]){
            A[front.first][front.second+1]+=1;
            q1.push(make_pair(front.first,front.second+1));
            ch[front.first][front.second+1]=true;
        }



    }

}