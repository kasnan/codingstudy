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

    // 인접 행렬 입력받아 저장
    // 인간 관계는 양방향이므로 두 위치의 데이터를 1로 입력
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        D[a][b] = 1;
        D[b][a] = 1;
    }


    // 케빈 베이컨은 두 노드에 대해 몇 개의 노드를 경유해 연결되어 있는 지를 파악하는 수치이다.
    // 한 노드에 대해 모든 노드의 단계를 합친 값이 케빈 베이컨의 수이다.
    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                // 출발 노드로부터 도착 노드까지의 단계에 대해 판단
                // 경유지를 통한 단계가 더 작으면 해당 값으로 업데이트
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // 제일 작은 케빈 베이컨의 단계를 찾기
    // 각 노드에 대해 인접 행렬의 모든 값을 합해 케빈 베이컨의 수를 파악
    // 가장 작은 케빈 베이컨의 수를 갖는 인덱스를 출력
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