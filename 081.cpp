#include<iostream>
using namespace std;

long F[21];
long Q[21];
int n,t;
long k;
bool visit[21];


int main(){
    cin >> n;

    F[0]=1;
    for(int i=1;i<=n;i++){
        F[i]=F[i-1]*i;
    }

    cin >> t;
    if(t==1){
        cin >> k;
        int cnt;
        for(int i=1;i<n+1;i++){
            for(int j=1,cnt=1;j<n+1;j++){
                
                if(visit[j]){
                    continue;
                }
                if(k<=cnt*F[n-i]){
                    k-=(F[n-i]*(cnt-1));
                    Q[i]=j;
                    visit[j]=true;
                    break;
                }
                cnt++;
            }
            
        }

        for(int i=1;i<n+1;i++){
            cout << Q[i] << ' ';
        }
    }
    else{
        k=1;
        long cnt;
        for(int i=1;i<n+1;i++){
            cin >> Q[i];
            cnt=0;
            for(int j=1;j<Q[i];j++){
                if(!visit[j]){
                    cnt++;
                }
            }
            k+=(cnt*F[n-i]);
            visit[Q[i]]=true;
        }
        cout << k << endl;


    }
}