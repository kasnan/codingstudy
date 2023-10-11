#include<iostream>
#include<tuple>

using namespace std;
int D[101][101][101];

int main(){
    int a,b,c;

    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<101;k++){
                if(i<=50 || j<=50 || k<=50){
                    D[i][j][k]=1;
                }
                else if(i>70 || j>70 || k>70){
                    D[i][j][k]=D[70][70][70];
                }
                else if(i<j<k){
                    D[i][j][k]=D[i][j][k-1]+D[i][j-1][k-1]-D[i][j-1][k];
                }
                else{
                    D[i][j][k]=D[i-1][j][k]+D[i-1][j-1][k]+D[i-1][j][k-1]-D[i-1][j-1][k-1];
                }
            }
        }
    }

    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1){
            break;
        }
        cout << "w(" <<a<<","<<b<<","<<c<<") = "<<D[a+50][b+50][c+50] << "\n";
    }
}