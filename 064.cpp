#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef struct edge{ // 에지 정보 구조체, 정렬 기준 연산도 구현
    int s,e,v;
    bool operator > (const edge&temp) const{
        return v > temp.v;
    }
}edge;

priority_queue<edge,vector<edge>,greater<edge>> edges;
vector<int> D;

int findF(int n);
void unionF(int a,int b);

int main(){
    int v,e;
    cin >> v >> e;

    D.resize(v+1);
    for(int i=1;i<v+1;i++){
        D[i]=i;
    }

    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push(edge{a,b,c});
    }

    int treecnt=0;
    int cntedge=0;
    while(cntedge<v-1){
        edge now = edges.top();
        edges.pop();

        if(findF(now.s)!=findF(now.e)){
            unionF(now.s,now.e);
            treecnt+=now.v;
            cntedge++;
        }
    }

    cout << treecnt << endl;
}

int findF(int n){
    if(D[n]==n){
        return n;
    }
    else{
        return D[n]=findF(D[n]);
    }
}

void unionF(int a,int b){
    a=findF(a);
    b=findF(b);
    if(a!=b){
        D[b]=a;
    }
}