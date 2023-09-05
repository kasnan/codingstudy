#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
    bool operator()(int n1, int n2){
        if(abs(n1)>abs(n2))
            return true;
        else if(abs(n1)==abs(n2)){
            if(n1 > n2)
                return true;
            else
                return false;
        }
        return false;
    }
};

int main()
{
    int N;
    cin >> N;

    // int형 변수들을 cmp 우선순위 기준에 맞춰 정렬하는 우선순위 큐
    // 중간 Container
    priority_queue<int, vector<int>, cmp> pq1;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        int inum;
        cin >> inum;
        if (inum == 0)
        {
            if (!pq1.empty())
            {
                int onum = pq1.top();
                pq1.pop();
                ans.push_back(onum);
            }
            else{
                ans.push_back(0);
            }
        }
        else
        {
            pq1.push(inum);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}