#include<iostream>

using namespace std;

int a,b,c;

int calc(int res,int cnt){
    if(cnt==0){
        return 1;
    }
    else if(cnt==1){
        return a;
    }
    return calc((res*a)%c,cnt);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    cout << calc(1,b)%c;

}