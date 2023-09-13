#include<iostream>

using namespace std;

int getgcd(int n1,int n2);

int main(){
    int alen,blen;
    cin >> alen >> blen;

    int gcd=getgcd(alen,blen);

    for(int i=0;i<gcd;i++){
        cout << 1;
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