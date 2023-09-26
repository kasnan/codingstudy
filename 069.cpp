#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node{
    public:
        Node* next[26];
        bool isEnd;
        Node() : isEnd(false){
            fill(next,next+26,nullptr);
        }

        ~Node(){
            for(auto& child : next){
                delete child;
            }
        }

        void insert(const char* key){
            if(*key==0){
                isEnd=true;
            }
            else{
                int next_idx=*key-'a';
                if(next[next_idx]==nullptr){
                    next[next_idx]=new Node();
                }
                next[next_idx] -> insert(key+1);
            }
        }

        Node* find(const char* key){
            if(*key==0){
                return this;
            }
            int next_idx = *key-'a';

            if(next[next_idx]==nullptr){
                return nullptr;
            }
            return next[next_idx] -> find(key+1);
        }

        
};

int main(){
    int n,m;
    cin >> n >> m;

    Node* root = new Node();

    for(int i=0;i<n;i++){
        // 트라이 생성
        char instr[501];
        cin >> instr;
        root -> insert(instr);

    }

    int cnt=0;
    // 입력받은 문자열이 트라이 안에 있는지 검색을 수행해 카운트
    for(int i=0;i<m;i++){
        char search[501];
        cin >> search;
        Node *res = root -> find(search);

        if(res && res -> isEnd){
            cnt++;
        }
    }

    cout << cnt << endl;
}