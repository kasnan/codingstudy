#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} Node;

static Node n[6];

void initdata(){
    for(int i=0;i<6;i++){
        n[i].data=i;
    }

    n[0].left=&n[2];
    n[0].right=&n[1];

    n[1].left=&n[5];
    n[1].right=&n[4];

    n[2].left=NULL;
    n[2].right=&n[3];

    n[3].left=NULL;
    n[3].right=&n[5];

    n[4].left=NULL;
    n[4].right=NULL;

    n[5].left=NULL;
    n[5].right=NULL;
}


int main(){
    
    stack<Node> s1;
    vector<bool> v1(6,false);

    // 샘플데이터 준비
    initdata();
    
    // 시작 데이터 지정
    int start=0;
    s1.push(n[start]);
    
    // DFS 시작
    // 스택에 값이 없을 때까지 반복 
    Node top;
    while(!s1.empty()){
        top=s1.top();
        s1.pop();

        cout << "visit " << top.data+1 << endl;
        v1[top.data]=true;

        if(top.right != NULL && v1[top.right->data] != true){
            s1.push(*top.right);
        }

        if(top.left != NULL && v1[top.left->data] != true){
            s1.push(*top.left);
        }
        
    }
}