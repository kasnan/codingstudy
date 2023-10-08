#include<iostream>

using namespace std;

int A[1000001];
int D[1000001];
int B[1000001];
int R[1000001];

int binarysearch(int l,int r,int now);
int n,maxlen;

int main(){
    cin >> n;

    for(int i=1;i<n+1;i++){
        cin >> A[i];
    }

    D[1]=1;
    int idx;
    B[++maxlen]=A[1];
    for(int i=2;i<n+1;i++){
        if(B[maxlen]<A[i]){
            B[++maxlen]=A[i];
            D[i]=maxlen;
        }
        else{
            idx=binarysearch(1,maxlen,A[i]);
            B[idx]=A[i];
            D[i]=idx;
        }
    }

    cout << maxlen << "\n";
    idx=maxlen;
    int x = B[maxlen]+1;

    for(int i=n;i>0;i--){
        if(D[i]==idx && A[i]<x){
            R[idx]=A[i];
            x=A[i];
            idx--;
        }
    }
    for(int i=1;i<maxlen+1;i++){
        cout << R[i] << ' ';
    }
}

int binarysearch(int l,int r,int now){
    int mid;
    while(l<r){
        mid=(l+r)/2;
        if(B[mid]<now){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return l;
}