#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> Inum,res;
bool chk[10001];
void Solution(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    int xx=-1;
    for(int i=0;i<Inum.size();i++){
        res[cnt]=Inum[i];
        Solution(cnt+1);
    }
}

void Solve(){
    Solution(0);
    return;
}

int main(){
    cin >> n >> m;

    // 중복되는 수는 제거
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(!chk[tmp]){
            Inum.push_back(tmp);
            chk[tmp]=true;
        }
    }
    sort(Inum.begin(),Inum.end());
    res.resize(m);
    Solve();
}