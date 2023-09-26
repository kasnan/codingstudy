#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

long getSum(int s,int e);
void updateVal(int idx,long val);
void setTree(int i);

vector<long> segtree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;

    // 세그먼트 트리 초기화
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

    for(int i=0;i<m+k;i++){
        long a,b,c;
        cin >> a >> b >> c;
        
        if(a==1){
            // a가 1이면 값 업데이트
            updateVal(b+startIndex,c);
        }
        else if(a==2){
            // a가 2이면 질의된 범위의 구간합 구하기
            b+=startIndex;
            c+=startIndex;
            cout << getSum(b,c) << endl;
        }
    }
}

void setTree(int i){
    while(i!=1){
        segtree[i/2]+=segtree[i];
        i--;
    }
}

long getSum(int s,int e){
    long partSum=0;

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

void updateVal(int idx,long val){
    long diff = val - segtree[idx];
    while(idx > 0){
        segtree[idx]+=diff;
        idx/=2;
    }
}