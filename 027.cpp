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
        for(int j=0;j<M;j++){
            A[i].push_back(col[j]-'0');
        }
    }

    // 시작 노드는 (0,0)
    // 도착 노드는 (N-1,M-1)
    Node start=make_pair(0,0);
    
    BFS(start);
    cout << A[N-1][M-1] << endl;

}

void BFS(Node start){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<Node> q1;
    q1.push(start);

    //상하좌우 순서대로 스캔
    //방문했던 노드가 아니고 갈 수 있는 위치는 push
    while(!q1.empty()){
        Node front = q1.front();
        q1.pop();
        ch[front.first][front.second]=true;

        for(int i=0;i<4;i++){
            int x = front.first + dx[i];
            int y = front.second + dy[i];

            if(-1<x<N && -1<y<M){
                // seg fault 에러 내일 풀고 정리하자
                if(A[x][y] != 0 && ch[x][y] == false){
                    ch[x][y]=true;
                    A[x][y]=A[front.first][front.second]+1;
                    q1.push(make_pair(x,y));
                }
            }
        }
    }

}