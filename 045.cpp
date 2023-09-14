#include<iostream>
#include<vector>

using namespace std;

vector<long> euclid_ex(long a,long b);
long getgcd(long a,long b);

vector<int>euclid;

int main(){
    long A,B,C;
    cin >> A >> B >> C;

    if(C%getgcd(A,B)!=0){
        cout << -1 << endl;
    }
    else{
        int mok=C/getgcd(A,B);
        vector<long>ret=euclid_ex(A,B);
        cout << ret[0]*mok << " " << ret[1]*mok << endl;
    }
}

long getgcd(long a,long b){
    if(b==0){
        return a;
    }
    else{
        getgcd(b,a%b);
    }
}

vector<long> euclid_ex(long a,long b){
    vector<long> ret(2);
    if(b==0){
        ret[0]=1;
        ret[1]=0;
        return ret;
    }
    else{
        long q=a/b;
        vector<long>v=euclid_ex(b,a%b);
        ret[0]=v[1];
        ret[1]=v[0]-v[1]*q;
        return ret;
    }
}