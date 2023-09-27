#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long> Tree;

static int MOD = 1000000007;

long getTime(int s,int e);
void setTree(int i);
void updateVal(int idx,int val);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;

    int treeH=0;
    int Length=n;

    while(Length!=0){
        Length/=2;
        treeH++;
    }

    int treesize=int(pow(2,treeH+1));
    int startIdx=treesize/2-1;

    Tree.resize(treesize+1);
    fill(Tree.begin(),Tree.end(),1);

    for(int i=startIdx+1;i<n+startIdx+1;i++){
        cin >> Tree[i];
    }
    setTree(treesize-1);

    for(int i=0;i<m+k;i++){
        long a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            b+=startIdx;
            updateVal(b,c);
        }
        else if(a==2){
            b+= startIdx;
            c+= startIdx;
            long res = getTime(b,c);
            cout << res << "\n";
        }
    }
}

void setTree(int i){
    while(i!=1){
        Tree[i/2]=Tree[i/2]*Tree[i]%MOD;
        i--;
    }
}

long getTime(int s,int e){
    long time=1;
    while(s<=e){
        if(s%2==1){
            time=time*Tree[s]%MOD;
            s++;
        }
        if(e%2==0){
            time=time*Tree[e]%MOD;
            e--;
        }
        s/=2;
        e/=2;
    }

    return time;
}

void updateVal(int idx,int val){
    Tree[idx]=val;
    while(idx>1){
        idx/=2;
        Tree[idx]=Tree[idx*2]%MOD*Tree[idx*2+1]%MOD;
    }

}