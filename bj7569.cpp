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

        for (int i = 0; i < 6; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nz = zz + dz[i];

            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < M && ny < N && nz < H)
            {
                if (BOX[nz][ny][nx] == 0)
                {
                    BOX[nz][ny][nx] = BOX[zz][yy][xx] + 1;
                    q.push({nz, ny, nx});
                }
            }
        }
    }
}

void tomato()
{
    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                cin >> BOX[z][y][x];

                if (BOX[z][y][x] == 1)
                {
                    q.push({z, y, x});
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

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (BOX[z][y][x] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                ans = max(ans, BOX[z][y][x]);
            }
        }
    }

    cout << ans - 1 << "\n";
}
