#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long n,result;
    cin >> n;

    result=n;

    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            result=result-result/i;
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1){
        result=result-result/n;
    }

    cout << result << endl;


}