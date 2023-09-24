#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(int i, int j);
int findF(int b);
void unionF(int a, int b);

typedef struct edge
{ // 에지 정보 구조체, 정렬 기준 연산도 구현
    int s, e, v;
    bool operator > (const edge &temp) const
    {
        return v > temp.v;
    }
} edge;

priority_queue<edge, vector<edge>, greater<edge>> pq;
// 섬 정보 저장
vector<vector<pair<int, int>>> sumlist;
// 하나의 섬 정보 저장
vector<pair<int, int>> mlist;

static int map[11][11];
static bool visit[11][11] = {
    false,
};
static vector<int> parent;
int n, m, sNum;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // 섬 구분
    // 모든 위치에서 BFS 수행

    // 1번부터 시작해서 구분되는 섬들에 각 값을 넣어준다.
    sNum = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 이전에 방문하지 않았고 땅인 경우 -> 새로운 섬
            if (!visit[i][j] && !map[i][j])
            {
                // 주변 탐색
                BFS(i, j);
                // 새로운 구분 값으로
                sNum++;
                // 섬에 대한 정보를 섬 리스트에 추가
                sumlist.push_back(mlist);
            }
        }
    }

    // 섬의 각 지점에서 만들 수 있는 모든 에지 저장
    for (int i = 0; i < sumlist.size(); i++)
    {
        // 현재 선택된 섬
        vector<pair<int, int>> now = sumlist[i];

        for (int j = 0; j < now.size(); j++)
        {
            // 현재 선택된 위치(행,열,섬번호)
            int r = now[j].first;
            int c = now[j].second;
            int now_s = map[r][c];

            // 주변 탐색
            for (int d = 0; d < 4; d++)
            {
                int tempC = dc[d];
                int tempR = dr[d];
                int blen = 0;

                // 
                while (0 <= r + tempR < n && 0 <= c + tempC < m)
                {
                    if (map[r + tempR][c + tempC] == now_s)
                    {
                        break;
                    }
                    else if (map[r + tempR][c + tempC] != 0)
                    {
                        if (blen > 1)
                        {
                            pq.push(edge{now_s, map[r + tempR][c + tempC], blen});
                        }
                        break;
                    }
                    else
                    {
                        blen++;
                    }

                    if (tempR < 0)
                    {
                        tempR--;
                    }
                    else if (tempR > 0)
                    {
                        tempR++;
                    }

                    else if (tempC < 0)
                    {
                        tempC--;
                    }
                    else if (tempC > 0)
                    {
                        tempC++;
                    }
                }
            }
        }
    }

    parent.resize(sNum);

    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }

    int useedge = 0;
    int res = 0;

    while (!pq.empty())
    {
        edge now = pq.top();
        pq.pop();
        int s= now.s;
        int e=now.e;
        if (findF(s) != findF(e))
        {
            unionF(now.s, now.e);
            res += now.v;
            useedge++;
        }
    }

    if (useedge == sNum - 2)
    {
        cout << res << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

void unionF(int a, int b)
{
    a = findF(a);
    b = findF(b);
    if (a > b)
    {
        parent[a] = b;
    }
    else{
        parent[b]=a;
    }
}

int findF(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        return parent[a] = findF(parent[a]);
    }
}

void BFS(int i, int j)
{
    queue<pair<int, int>> q1;
    mlist.clear();

    q1.push(make_pair(i, j));
    mlist.push_back(make_pair(i, j));
    visit[i][j] = true;
    map[i][j] = sNum;

    while (!q1.empty())
    {
        int r = q1.front().first;
        int c = q1.front().second;
        q1.pop();

        for (int d = 0; d < 4; d++)
        {
            int tempr = dr[d];
            int tempc = dc[d];

            while (0 <= r+tempr &&r+tempr< n && 0 <= c+tempc &&c+tempc< m)
            {
                if (!visit[r+tempr][c+tempc] && map[r+tempr][c+tempc] != 0)
                {
                    int now_i = r+tempr;
                    int now_j = c+tempc;

                    map[now_i][now_j] = sNum;
                    visit[now_i][now_j] = true;

                    mlist.push_back(make_pair(now_i, now_j));
                    q1.push(make_pair(now_i, now_j));
                }
                else
                {
                    break;
                }

                if (tempr < 0)
                {
                    tempr--;
                }
                else if (tempr > 0)
                {
                    tempr++;
                }

                else if (tempc < 0)
                {
                    tempc--;
                }
                else if (tempc > 0)
                {
                    tempc++;
                }
            }
        }
    }
}