#include <iostream>
#include <limits.h>
using namespace std;

long D[101][101];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i == j)
            {
                D[i][j] = 0;
            }
            else
            {
                D[i][j] = 987654321;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        D[a][b] = 1;
        D[b][a] = 1;
    }

    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    int min = INT_MAX;
    int minind;
    for (int i = 1; i < n + 1; i++)
    {
        int tmp = 0;
        for (int j = 1; j < n + 1; j++)
        {
            tmp += D[i][j];
        }
        if (min > tmp)
        {
            min = tmp;
            minind = i;
        }
    }

    cout << minind << endl;
}