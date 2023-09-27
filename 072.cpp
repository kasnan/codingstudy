#include<iostream>
#include<cmath>
#include<vector>
#include<limits.h>
using namespace std;

vector<long> segtree;
long getMin(int s,int e);
void setTree(int i);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    int treeHeight=0;
    int Length=n;

    while(Length!=0){
        Length/=2;
        treeHeight++;
    }

    int treeSize=int(pow(2,treeHeight+1));
    int startIndex=treeSize/2-1;
    segtree.resize(treeSize+1);
    fill(segtree.begin(),segtree.end(),LONG_MAX);

    // 데이터 입력(시작 위치부터 데이터 입력)
    for(int i=startIndex+1;i<startIndex+n+1;i++){
        cin >> segtree[i];
    }
    setTree(treeSize);

    for(int i=0;i<m;i++){
        long a,b;
        cin >> a >> b;

        a+=startIndex;
        b+=startIndex;

        cout << getMin(a,b) << "\n";
    }
}

void setTree(int i){
    while(i!=1){
        if(segtree[i/2]>segtree[i]){
            segtree[i/2]=segtree[i];
        }
        i--;
    }
}
long getMin(int s,int e){
    long minv=LONG_MAX;

    while(s<=e){
        if(s%2==1){
            minv=min(minv,segtree[s]);
            s++;
        }
        if(e%2==0){
            minv=min(minv,segtree[e]);
            e--;
        }
        s/=2;
        e/=2;
    }

    return minv;
}