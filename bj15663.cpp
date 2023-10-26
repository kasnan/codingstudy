#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> Inum;
vector<int> res;
vector<bool> chk;
void Solution(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    int xx=0;
    for(int i=0;i<n;i++){
        if(!chk[i] && Inum[i]!=xx){
            res[cnt]=Inum[i];
            xx=res[cnt];
            chk[i]=true;
            Solution(cnt+1);
            chk[i]=false;
        }
    }
}

void Solve(){
    Solution(0);
    return;
}

int main(){
    cin >> n >> m;
    Inum.resize(n);
    res.resize(m);
    chk.resize(n);
    fill(chk.begin(),chk.end(),false);
    for(int i=0;i<n;i++){
        cin >> Inum[i];
    }
    sort(Inum.begin(),Inum.end());

    Solve();
}