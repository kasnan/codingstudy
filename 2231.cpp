#include<iostream>
#include<math.h>
using namespace std;

int eachsum(int num){
    int firstpos;
    int numarr[7]={0,};
    int index=0,sum=0;
    while(num>=1){
        numarr[index]=num%10;
        index++;
        num/=10;
    }
    for(int i=0;i<7;i++){
        sum+=numarr[i];
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    int sum, tmp;
    tmp=sum/2+1;
    while(true){
        sum=tmp+eachsum(tmp);
        if(sum == N){
            break;
        }
        else if(tmp>=N){
            cout << 0;
            return 0;
        }
        tmp++;
    }
    
    cout << tmp;
}