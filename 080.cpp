#include<iostream>
#include<vector>
using namespace std;

int S[51];
double ans=0.0;
int m,k,n;
int main(){
    cin >> m;

    for(int i=0;i<m;i++){
        cin >> S[i];
        n+=S[i];
    }

    cin >> k;
    for(int i=0;i<m;i++){
        double tmp=0.0;
        if(S[i]>=k){
            tmp=1.0;
            for(int j=0;j<k;j++){
                tmp*=(double)(S[i]-j)/(n-j);
            }
        }
        ans+=tmp;
    }

    cout << fixed;
    cout.precision(15);
    cout << ans;
}