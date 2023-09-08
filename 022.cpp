#include<iostream>
#include<vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    // 문제가 의도한 답안
    vector<int> count(10001,0);
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        count[tmp]++;
    }

    for(int i=0;i<10001;i++){
        if(count[i]!=0){
            for(int j=0;j<count[i];j++){
                cout << i << endl;
            }
        }
    }
}