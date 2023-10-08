#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

static int cost[5][5] = {{0, 2, 2, 2, 2},
                         {2, 1, 3, 4, 3},
                         {2, 3, 1, 3, 4},
                         {2, 4, 3, 1, 3},
                         {2, 3, 4, 3, 1}};
static long D[100001][5][5];

int main()
{

    int step = 1,note;
    for (int i = 0; i < 100001; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                D[i][j][k] = 100001 * 9;
            }
        }
    }

    D[0][0][0] = 0;

    while (true)
    {
        cin >> note;
        if (note == 0)
        {
            step--;
            break;
        }
        // 오른발 이동
        for (int i = 0; i < 5; i++)
        {
            if (note == i)
            {
                continue;
            }
            for (int j = 0; j < 5; j++)
            {
                D[step][i][note] = min(D[step - 1][i][j] + cost[j][note], D[step][i][note]);
            }
        }

        // 왼발 이동
        for (int j = 0; j < 5; j++)
        {
            if (note == j)
            {
                continue;
            }
            for (int i = 0; i < 5; i++)
            {
                D[step][note][j] = min(D[step - 1][i][j] + cost[i][note], D[step][note][j]);
            }
        }
        step++;
    }
    
    long minval = INT_MAX;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            minval = min(minval, D[step][i][j]);
        }
    }

    cout << minval << endl;
}