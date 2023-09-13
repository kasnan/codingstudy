#include<iostream>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

bool isPal(long n);

int main(){
    int N;
    cin >> N;

    vector<long>P(10000001,0);
    for(int i=2;i<10000001;i++){
        P[i]=i;
    }

    for(int i=2;i<10000001;i++){
        if(P[i]>0){
            for(int j=i+i;j<10000001;j+=i){
                P[j]=0;
            }
        }
    }

    long start=N;
    while(true){
        if(isPal(start)){
            if(P[start]>0){
                break;
            }
        }
        start++;
    }

    cout << start << endl;
}

bool isPal(long n){
    bool res=true;
    string proc=to_string(n);
    int strsize = proc.size();

    for(int i=0;i<strsize/2;i++){
        if(proc[i]!=proc[strsize-1-i]){
            res=false;
            break;
        }
    }

    return res;
}
