#include<iostream>
#include<climits>
using namespace std;

long D[501][501];
pair<int,int> M[501];

long exec(int s,int e);
int main(){
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            D[i][j]=-1;
        }
    }

    int n;
    cin >> n;
    for(int i=1;i<n+1;i++){
        cin >> M[i].first >> M[i].second;
    }

    long res=exec(1,n);
    cout << res << endl;
}

long exec(int s,int e){
    long res=INT_MAX;
    if(D[s][e]!=-1){
        return D[s][e];
    }
    else if(s==e){
        return 0;
    }
    else if(e==s+1){
        return M[s].first*M[e].first*M[e].second;
    }
    else{
        for(int i=s;i<e+1;i++){
            res=min(res,M[s].first*M[i].second*M[e].second+exec(s,i)+exec(i+1,e));
        }
    }

    return D[s][e]=res;
}