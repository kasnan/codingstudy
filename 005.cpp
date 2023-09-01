#include<iostream>
#include<vector>

using namespace std;

int main(){
    

    int N,M;
    long count=0;

    cin >> N >> M;

    vector<long> S(N,0);
    vector<long> C(M,0);
    cin >> S[0];

    for(int i=1;i<N;i++){
        long tmp;
        cin >> tmp;
        S[i] = S[i-1] + tmp;
    }

    for(int i=0;i<N;i++){
        int remainder = S[i]%M;
        if(remainder == 0){
            count++;
        }
        C[remainder]++;
    }

    for(int i=0;i<M;i++){
        if(C[i]>1){
            count+=(C[i]*(C[i]-1)/2);
        }
    }

    cout << count << endl;


}