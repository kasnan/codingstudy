#include<iostream>
#include<vector>

using namespace std;
vector<int> R;
vector<int> P;

void unionfunc(int a,int b);
int findfunc(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    R.resize(n+1);
    P.resize(m);

    for(int i=1;i<n+1;i++){
        R[i]=i;
    }


    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int tmp;
            cin >> tmp;
            if(tmp){
                unionfunc(i,j);
            }
        }
    }

    for(int i=0;i<m;i++){
        cin >> P[i];
    }

    bool available=true;
    int check=R[P[0]];
    for(int i=1;i<m;i++){
        if(check!=R[P[i]]){
            available=false;
            break;
        }
    }

    if(available){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int findfunc(int a){
    if(R[a]==a){
        return a;
    }
    else{
        return R[a]=findfunc(R[a]);
    }
}

void unionfunc(int a,int b){
    a=findfunc(a);
    b=findfunc(b);
    if(a>b){
        R[a]=b;
    }
    else{
        R[b]=a;
    }
}