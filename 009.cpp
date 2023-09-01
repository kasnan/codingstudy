#include <iostream>
#include <vector>

using namespace std;

vector<int> vcnt(4, 0);

void add(char ch1)
{
    switch (ch1)
    {
    case 'A':
        vcnt[0]++;
        break;
    case 'C':
        vcnt[1]++;
        break;
    case 'G':
        vcnt[2]++;
        break;
    case 'T':
        vcnt[3]++;
        break;
    }
}

void del(char ch1)
{
    switch (ch1)
    {
    case 'A':
        vcnt[0]--;
        break;
    case 'C':
        vcnt[1]--;
        break;
    case 'G':
        vcnt[2]--;
        break;
    case 'T':
        vcnt[3]--;
        break;
    }
}

int main()
{

    int Slen, Plen;
    string S;
    int A, C, G, T;

    cin >> Slen >> Plen;
    cin >> S;
    cin >> A >> C >> G >> T;

    int start, end;
    start = 0;
    end = Plen-1;

    int count = 0;

    // 처음 윈도우를 위치시키고 확인
    for (int i = start; i < end + 1; i++)
    {
        add(S[i]);
    }

    while (end < Slen)
    {
        // 조건 충족하는 지 확인
        if (vcnt[0] >= A && vcnt[1] >= C && vcnt[2] >= G && vcnt[3] >= T)
        {
            count++;
        }

        // 다음 윈도우로 슬라이드
        // 하나 추가, 하나 제거
        del(S[start]);
        start++;
        end++;
        add(S[end]);
    }

    cout << count << endl;
}