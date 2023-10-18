#include <iostream>
 
#define endl "\n"
#define MAX 35
using namespace std;
 
int N;
int DP[MAX];
 

 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    if (N % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    for (int i = 4; i <= N; i = i + 2)
    {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            DP[i] = DP[i] + (DP[j] * 2);
        }
    }
    cout << DP[N] << endl;

    return 0;
}