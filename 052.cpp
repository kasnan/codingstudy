#include<iostream>
#include<vector>

using namespace std;

int findfunc(int n);
void unionfunc(int a,int b);

vector<int> A;
vector<int> truthp;
vector<vector<int>> party;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    A.resize(n+1);
    party.resize(m);

    for(int i=1;i<n+1;i++){
        A[i]=i;
    }

    int truep;
    cin >> truep;

    truthp.resize(truep);
    // 초기 진실을 아는 사람들
    for(int i=0;i<truep;i++){
        cin >> truthp[i];
    }


    int cnt=0;

    // 각 파티 정보
    // 각 파티에 참여하면 같은 집합에 속하도록 union 연산 수행
    for(int i=0;i<m;i++){
        int size;
        cin >> size;

        int first;
        cin >> first;
        party[i].push_back(first);

        for(int j=1;j<size;j++){
            int person;
            cin >> person;
            party[i].push_back(person);
            unionfunc(first,person);
        }
    }

    // 각 파티에서 사람들을 각 파티의 첫번째 사람의 집합에 속하도록 처리.
    // 진실 아는 사람들과 같은 집합에 속하는 지 각 파티의 대표노드와 비교
    // 각 파티의 첫 번째 사람과 비교

    bool available;
    for(int i=0;i<m;i++){
        int first=party[i][0];
        available=true;
        for(int j=0;j<truep;j++){
            if(findfunc(first)==findfunc(truthp[j])){
                available=false;
                break;
            }
        }
        if(available){
            cnt++;
        }
    }

    cout << cnt << endl;
}

int findfunc(int n){
    if(A[n]==n){
        return n;
    }
    else{
        return A[n]=findfunc(A[n]);
    }
}

void unionfunc(int a, int b){
    a=findfunc(a);
    b=findfunc(b);
    if(a>b){
        A[a]=b;
    }
    else{
        A[b]=a;
    }
}