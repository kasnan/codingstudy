#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
int Inum[8],res[8];
bool chk[8];
void Solution(int cnt,int start){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    int xx=-1;
    for(int i=start;i<n;i++){
        if(!chk[i] && Inum[i]!=xx){
            res[cnt]=Inum[i];
            xx=res[cnt];
            chk[i]=true;
            Solution(cnt+1,i);
            chk[i]=false;
        }
    }
}

void Solve(){
    Solution(0,0);
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> Inum[i];
    }
    sort(Inum,Inum+n);

    Solve();
}