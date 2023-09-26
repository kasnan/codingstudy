#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> segtree;

int getMin(int s,int e);
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

    // 데이터 입력(시작 위치부터 데이터 입력)
    for(int i=startIndex+1;i<startIndex+n+1;i++){
        cin >> segtree[i];
    }
    
    // 입력된 데이터 상위 노드들 데이터 연산
    // 구간 합이니 두 자식 노드의 합이 부모 노드의 값
    setTree(treeSize-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;

        a+=startIndex;
        b+=startIndex;

        cout << getMin(a,b) << endl;
    }
}

void setTree(int i){
    while(i!=1){
        segtree[i/2]=min(segtree[i/2*2],segtree[i/2*2+1]);
        i--;
    }
}
int getSum(int s,int e){
    int partSum=0;

    while(s<=e){
        if(s%2==1){
            partSum+=segtree[s];
            s++;
        }
        if(e%2==0){
            partSum+=segtree[e];
            e--;
        }
        s/=2;
        e/=2;
    }

    return partSum;
}