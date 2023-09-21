#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> A;
vector<long> D;

int main()
{
    int n, m;
    cin >> n >> m;

    // edge list와 D 배열 초기화
    A.resize(m);
    D = vector<long>(n + 1, LONG_MAX);
    // 시작 도시는 1번 도시
    D[1] = 0;

    // edge 정보 입력
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        A[i] = edge(a, b, c);
    }

    // node개수 - 1 횟수 만큼 각 에지를 활용한다
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            edge cur = A[j];
            int s = get<0>(cur);
            int e = get<1>(cur);
            int w = get<2>(cur);

            if (D[s] != LONG_MAX && D[e] > D[s] + w)
            {
                D[e] = D[s] + w;
            }
        }
    }

    // 시간을 무한히 돌릴 수 있는 즉, 음수 사이클의 존재 여부 확인
    bool ncycle = false;

    for (int j = 0; j < m; j++)
    {
        edge cur = A[j];
        int s = get<0>(cur);
        int e = get<1>(cur);
        int w = get<2>(cur);

        if (D[s] != LONG_MAX && D[e] > D[s] + w)
        {
            ncycle = true;
            break;
        }
    }

    if (!ncycle)
    {
        for (int i = 2; i < n + 1; i++)
        {
            if (D[i] != LONG_MAX)
            {
                cout << D[i] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    else
    {
        cout << -1 << endl;
    }
}