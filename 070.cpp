#include<iostream>

using namespace std;

void pretrav(int r);
void intrav(int r);
void posttrav(int r);

int tree[26][2];

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        char p,l,r;
        cin >> p >> l >> r;
        int idx=p-'A';
        if(l!='.'){
            tree[idx][0]=l-'A';
        }
        else{
            tree[idx][0]=-1;
        }
        
        if(r!='.'){
            tree[idx][1]=r-'A';
        }
        else{
            tree[idx][1]=-1;
        }
    }

    pretrav(0);
    cout << "\n";
    intrav(0);
    cout << "\n";
    posttrav(0);
    cout << "\n";

}

void pretrav(int r){
    // 전위 순회 : root - left child - right child
    cout << char(r+'A');
    if(tree[r][0]!=-1){
        pretrav(tree[r][0]);
    }
    if(tree[r][1]!=-1){
        pretrav(tree[r][1]);
    }
}
void intrav(int r){
    // 중위 순회 : left child - root - right child
    if(tree[r][0]!=-1){
        intrav(tree[r][0]);
    }
    cout << char(r+'A');
    if(tree[r][1]!=-1){
        intrav(tree[r][1]);
    }
}

void posttrav(int r){
    // 후위 순회 : left child - right child - root
    if(tree[r][0]!=-1){
        posttrav(tree[r][0]);
    }
    if(tree[r][1]!=-1){
        posttrav(tree[r][1]);
    }
    cout << char(r+'A');
}

