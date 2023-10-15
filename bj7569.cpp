#include <iostream>
#include <queue>

using namespace std;

typedef struct point
{
    int z, y, x;
} point;

queue<point> q;
int BOX[100][100][100];
int ans = 0;
int M, N, H;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void tomatoBFS()
{
    while (!q.empty())
    {
        int xx = q.front().x;
        int yy = q.front().y;
        int zz = q.front().z;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nz = zz + dz[i];

            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < M && ny < N && nz < H)
            {
                if (BOX[nx][ny][nz] == 0)
                {
                    BOX[nx][ny][nz] = BOX[xx][yy][zz] + 1;
                    q.push({nz, ny, nx});
                }
            }
        }
    }
}

void tomato()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> BOX[i][j][k];

                if (BOX[i][j][k] == 1)
                {
                    q.push({i, j, k});
                }
            }
        }
    }
}
int main()
{
    cin >> M >> N >> H;
    tomato();
    tomatoBFS();

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (BOX[i][j][k] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                ans = max(ans, BOX[i][j][k]);
            }
        }
    }

    cout << ans - 1 << "\n";
}
