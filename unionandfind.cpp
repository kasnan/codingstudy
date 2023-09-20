#include<iostream>
#include<vector>

using namespace std;

vector<int> A(7);

void unionfunc(int a,int b);
int findfunc(int n);

int main(){
    
    for(int i=1;i<7;i++){
        A[i]=i;
    }

    // 1. union(1,4)
    unionfunc(1,4);
    // 2. find(5)
    int res = findfunc(4);
    cout << res << endl;

}

void unionfunc(int a,int b){
    // 조건에 따라 한 노드를 대표로 정하고 다른 노드를 대표 노드에 속하게 한다.
    // 집합 배열을 선언해서 해당 노드의 인덱스의 값을 대표 노드로 한다.
    a=findfunc(a);
    b=findfunc(b);
    if(a>b){
        A[a]=b;
    }
    else{
        A[b]=a;
    }
    
}

int findfunc(int n){
    // 대표 노드는 집합 배열에서 해당 노드의 인덱스와 값이 같다
    if(A[n]==n){
        return n;
    }
    // 인덱스와 값이 다르면 다른 대표 노드에 속한 노드이므로
    // 대표 노드를 찾을 때까지 재귀 호출을 수행한다.
    // 재귀 호출 과정에서 대표 노드에 속한 자식 노드들의 집합 배열 값을 
    // 대표 노드로 바꿀 수 있도록 return 문에 삽입 연산도 함께 넣는다.
    else{
        return A[n]=findfunc(A[n]);
    }
}