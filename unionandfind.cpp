#include<iostream>
#include<vector>

using namespace std;

vector<int> A(7);

void un(int p,int c);
int fi(int n);

int main(){
    
    for(int i=1;i<7;i++){
        A[i]=i;
    }

    // 1. union(1,4)
    un(1,4);
    // 2. find(5)
    int res = fi(4);
    cout << res << endl;

}

void un(int p,int c){
    // 대표 노드 p의 값(집합 값)으로 자식 노드 c의 값을 변경
    A[c]=A[p];
}

int fi(int n){
    if(A[n]==n){
        return n;
    }
    else{
        return A[n]=fi(A[n]);
    }
}