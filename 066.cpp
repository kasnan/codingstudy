#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

typedef struct edge{ // 에지 정보 구조체, 정렬 기준 연산도 구현
    int s,e,v;
    bool operator > (const edge&temp) const{
        return v > temp.v;
    }
}edge;

vector<int> parent;

int findF(int n);
void unionF(int a,int b);

int main(){
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    int n,sum;

    cin >> n;
    sum=0;

    char cable;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cable;
            if(cable=='0'){
                continue;
            }
            else{
                int len;
                if(isupper(cable)){
                    len=cable-'A'+27;
                }
                else if(islower(cable)){
                    len=cable-'a'+1;
                }
                sum+=len;
                if(i!=j){
                    if(len!=0){
                        // i->j의 edge
                        pq.push(edge{i,j,len});
                    }
                }
            }
            
        }
    }

    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int res=0;
    int edgecnt=0;

    while(!pq.empty()){
        edge now = pq.top();
        pq.pop();
        
        int s=now.s;
        int e=now.e;
        if(findF(s)!=findF(e)){
            unionF(s,e);
            res+=now.v;
            edgecnt++;
        }

    }

    if(edgecnt==n-1){
        cout << sum - res << endl;
    }
    else{
        cout <<-1 << endl;
    }

}

int findF(int n){
    if(parent[n]==n){
        return n;
    }
    else{
        return parent[n]=findF(parent[n]);
    }
}

void unionF(int a,int b){
    a=findF(a);
    b=findF(b);
    if(a!=b){
        if(b>a){
            parent[b]=a;
        }
        else{
            parent[a]=b;
        }
    }
}