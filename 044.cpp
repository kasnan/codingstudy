#include<iostream>
#include<vector>

using namespace std;

long getgcd(long n1,long n2);
void DFS(int n);

typedef pair<int,int> ratio;
typedef pair<int,ratio> Node;

vector<vector<Node>> A;
vector<bool> ch;
vector<long> D;
long lcm;

int main(){
    int N;
    cin >> N;
    A.resize(10);
    D.resize(10);
    ch=vector<bool>(10,false);

    lcm=1;
    // 그래프 저장
    for(int i=0;i<N-1;i++){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        A[a].push_back(Node(b,ratio(p,q)));
        A[b].push_back(Node(a,ratio(q,p)));

        // 입력받은 모든 비율에 대해 최소공배수를 구하기
        // 곱하는 것은 이후 최대공약수를 구해서 처리
        lcm*=(p*q/getgcd(p,q));
    }

    D[0]=lcm;
    DFS(0);

    long mgcd=D[0];
    for(int i=1;i<N;i++){
        mgcd=getgcd(mgcd,D[i]);
    }

    for(int i=0;i<N;i++){
        cout << D[i]/mgcd << ' ';
    }

}

long getgcd(long n1,long n2){
    if(n2==0){
        return n1;
    }
    else{
        getgcd(n2,n1%n2);
    }
}

void DFS(int n){
    ch[n]=true;

    for(Node i : A[n]){
        int next = i.first;
        if(!ch[next]){
            D[next]=D[n]*i.second.second/i.second.first;
            DFS(next);
        }
    }
}