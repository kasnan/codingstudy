#include <iostream>
#include <vector>
#include <stack>



using namespace std;

int main()
{

    int N;
    cin >> N;
    int top = 1;

    vector<int> v1(N,0);
    
    
    for (int i = 0; i < N; i++)
    {
        cin >> v1[i];
    }

    vector<char> ans;
    stack<int> s1;

    bool res = true; 

    for (int i = 0; i < v1.size(); i++)
    {
        int vnum = v1[i];
        if (vnum >= top)
        {
            while (vnum >= top)
            { 
                s1.push(top);
                ans.push_back('+');
                top++;
            }
            s1.pop();
            ans.push_back('-');
        }
        else
        {
            int tmp = s1.top();
            s1.pop();
            if(tmp > vnum){
                cout << "NO" << endl;
                res = false;
                break;
            }
            else{
                ans.push_back('-');
            }
        }
    }
    
    if(res){
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << endl;
        }
    }
}