#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N;

    vector<int> A(N+1);
    for(int i=1;i<N+1;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    cin >> M;
    vector<int> C(M);
    vector<int> ANS(M,0);
    for(int i=0;i<M;i++){
        cin >> C[i];
    }

    for(int i=0;i<M;i++){
        int target = C[i];
        
        int start=1;
        int end=N;
        int mid=(start+end)/2;
        while(start<=end){
            if(A[mid]==target){
                ANS[i]=1;
                break;
            }
            else if(A[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }

            mid=(start+end)/2;            
        }
        
    }
    for(int i=0;i<M;i++){
        cout << ANS[i] << endl;
    }
}