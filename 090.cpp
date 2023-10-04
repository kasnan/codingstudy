#include<iostream>

using namespace std;

int D[1000][1000];

int main(){
    string s1,s2;
    cin >> s1 >> s2;

    int col,row;
    col=s1.length();
    row=s2.length();


    // D테이블 초기화
    bool flag=false;
    for(int i=0;i<col;i++){
        if(flag){
            D[i][0]=1;
        }
        else if(s1[i]==s2[0]){
            D[i][0]=1;
            flag=true;
        }
        else{
            D[i][0]=0;
        }
    }

    for(int i=1;i<col;i++){
        for(int j=1;j<row;j++){
            if(s1[i]==s2[j]){
                D[i][j]=D[i-1][j-1]+1;
            }
            else{
                D[i][j]=max(D[i-1][j],D[i][j-1]);
            }
        }
    }
    
}