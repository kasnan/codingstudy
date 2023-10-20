#include<iostream>
#define MOD 1000000

using namespace std;

string code;
int D[5001];
int A[5001];
int p;
int main(){
    cin >> code;
    int len=code.length();
    if(len==1 && code[0] == '0'){
        cout << 0;
        return 0;
    }

    for(int i=1;i<len+1;i++){
        A[i]=code[i-1]-'0';
    }

    D[0]=1;
    for(int i=1;i<len+1;i++){
        if(A[i]>=1 && A[i]<=9){
            D[i]=D[i-1];
        }

        if(i==1) continue;

        p=A[i-1]*10+A[i];
        if(p>=10 && p<=26){
            D[i]=(D[i]+D[i-2])%MOD;
        }
    }
    cout << D[len] % MOD;
}