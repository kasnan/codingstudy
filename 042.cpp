#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int getgcd(int n1,int n2);

int main(){
    int T;
    int A,B;
    int lcm;

    vector<int>ans;
    
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> A >> B;
        lcm = A*B/getgcd(A, B);
        ans.push_back(lcm);
    }

    for(int i=0;i<T;i++){
        cout << ans[i] << endl;
    }
}

int getgcd(int n1,int n2){
    if(n2==0){
        return n1;
    }
    else{
        getgcd(n2,n1%n2);
    }
}