#include<iostream>
#include<vector>
#include<string>

using namespace std;

void swapnums(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    string instr;
    cin >> instr;

    vector<int> A;
    
    for(int i=0;i<instr.size();i++){
        int tmp = instr[i] - '0';
        A.push_back(tmp);
    }

    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            if(A[i]<A[j]){
                swapnums(&A[i],&A[j]);
            }
        }
    }

    for(int i=0;i<A.size();i++){
        cout << A[i];
    }
}