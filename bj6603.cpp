#include<iostream>

using namespace std;

int arr[12],res[6];
bool chk[13]={false, };
int k;

void Solution(int cnt,int start){
    if(cnt==6){
        for(int i=0;i<6;i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    int xx=0;
    for(int i=start;i<k;i++){
        if(!chk[i] && xx!=arr[i]){
            res[cnt]=arr[i];
            xx=arr[i];

            chk[i]=true;
            Solution(cnt+1,i);
            chk[i]=false;
        }
    }
}

int main(){
    while(true){
        cin >> k;
        if(k==0){
            break;
        }

        for(int j=0;j<k;j++){
            cin >> arr[j];
        }
        Solution(0,0);
        cout << "\n";

    }
}