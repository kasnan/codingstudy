#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Node;


int main()
{
    int N, L;
    cin >> N >> L;

    deque<Node> D;
    vector<int> res;

    // 새롭게 수 입력 : now
    for (int i = 0; i < N; i++)
    {
        int now;
        cin >> now;
        // 새롭게 값이 입력되면 기존 값과 비교
        while(D.size() && D.back().first > now){
            // 새롭게 입력되면 제거
            D.pop_back();
        }
        D.push_back(Node(now,i));
        if(D.front().second <= i-L){
            D.pop_front();
        }

        res.push_back(D.front().first);
        // cout << D.front().first << " ";        
    }

    vector<int>::iterator iter;
    for(iter=res.begin();iter<res.end();iter++){
        cout << *iter << ' ';
    }
}