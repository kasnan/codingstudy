#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    int k=log2(N);
    if(pow(2,k)<N)
        k++;
    cout << k;
}