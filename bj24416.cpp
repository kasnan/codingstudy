#include<iostream>

using namespace std;

int fib(int n);
int fib2(int n);

int main(){
    int n;
    cin >> n;
    int res1,res2;

    res1=fib(n);
    res2=fib2(n);

    cout << res1 << " " << res2;
}

int fib(int n){
    if(n==1 || n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int fib2(int n){
    return n-2;
}