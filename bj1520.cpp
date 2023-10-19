#include<iostream>
 
#define endl "\n"
#define MAX 500
using namespace std;
 
int N, M, Answer;
int MAP[MAX][MAX];
int DP[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int DFS(int x, int y)
{
    // 끝에 도달하면 1 반환
    if (x == N - 1 && y == M - 1) return 1;
    // 갈 수 있는 노드이고, 이전에 이미 경로 연산을 완료한 경우
    // 해당 노드의 경로 수를 반환
    if (DP[x][y] != -1) return DP[x][y];

    DP[x][y] = 0;
    // 인접 노드 탐색
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M)
        {
            // 더 낮은 높이의 노드인 경우
            if (MAP[nx][ny] < MAP[x][y])
            {
                // 현재 노드에서 다음 노드까지 갈 수 있는 경로의 수
                DP[x][y] = DP[x][y] + DFS(nx, ny);
            }
        }
    }
    return DP[x][y];
}
 
void Solution()
{
    Answer = DFS(0, 0);
    cout << Answer << endl;
}
 
void Solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            DP[i][j] = -1;
        }
    }
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
 
    return 0;
}