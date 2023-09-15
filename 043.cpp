#include<iostream>

using namespace std;

long getgcd(long n1,long n2);

int main(){
    long alen,blen;
    cin >> alen >> blen;

    long gcd=getgcd(alen,blen);

    for(long i=0;i<gcd;i++){
        cout << 1;
    }

}

long getgcd(long n1,long n2){
    if(n2==0){
        return n1;
    }
    else{
        return getgcd(n2,n1%n2);
    }
}