#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int t, m, n, k;
int x, y, ans;
int map[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    map[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n)
            continue;
        if (map[nextx][nexty] == 1)
        {
            dfs(nextx, nexty);
        }
    }
}

int main()
{
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            map[x][y] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == 1)
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        cout << ans << '\n';
        ans = 0;
        memset(map,0,sizeof(map));
    }
}