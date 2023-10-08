#include<iostream>
#include<climits>
#include<vector>
using namespace std;

long D[502][502];
vector<pair<int,int>> M;

int exec(int s,int e);
int main(){
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            D[i][j]=-1;
        }
    }

    int n;
    cin >> n;
    M.resize(n+1);
    for(int i=1;i<n+1;i++){
        int r,c;
        cin >> r >> c;
        M[i] = make_pair(r,c);
    }

    cout << exec(1,n) << endl;
}

int exec(int s,int e){
    int res=INT_MAX;
    if(D[s][e]!=-1){
        return D[s][e];
    }
    else if(s==e){
        return 0;
    }
    else if(e==s+1){
        return M[s].first*M[e].first*M[e].second;
    }
    for(int i=s;i<e;i++){
        res=min(res,M[s].first*M[i].second*M[e].second+exec(s,i)+exec(i+1,e));
    }

    return D[s][e]=res;
}