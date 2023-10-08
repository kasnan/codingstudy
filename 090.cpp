#include<iostream>
#include<vector>
using namespace std;

int D[1001][1001];
string s1,s2;
vector<char> res;
void getText(int i,int j);
int main(){
    
    cin >> s1 >> s2;

    for(int i=1;i<s1.size()+1;i++){
        for(int j=1;j<s2.size()+1;j++){
            if(s1[i-1]==s2[j-1]){
                D[i][j]=D[i-1][j-1]+1;
            }
            else{
                D[i][j]=max(D[i-1][j],D[i][j-1]);
            }
        }
    }
    cout << D[s1.size()][s2.size()] << "\n";
    if(D[s1.size()][s2.size()]){
        // LCS 출력
        // 테이블 왼쪽과 위쪽중 같은 값을 선택
        getText(s1.size(),s2.size());
        for(int i=res.size()-1;i>-1;i--){
            cout << res[i];
        }
    }
}

void getText(int i,int j){
    if(i==0 || j==0){
        return;
    }

    if(s1[i-1]==s2[j-1]){
        res.push_back(s1[i-1]);
        getText(i-1,j-1);
    }
    else {
        if(D[i-1][j]>D[i][j-1]){
            getText(i-1,j);
        }
        else{
            getText(i,j-1);
        }
    }
}