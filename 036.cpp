#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

vector<string> split(string input,char del);
int isSum(string input);

int main(){
    string inform;
    cin >> inform;

    vector<string>v1=split(inform,'-');
    int ans=0;

    for(int i=0;i<v1.size();i++){
        int tmp=isSum(v1[i]);
        if(i==0){
            ans+=tmp;
        }
        else{
            ans-=tmp;
        }
    }

    cout << ans << endl;

}

// C++에서 string을 쪼개는 방법
// 알고리즘 자체는 쉬우나 C++에 대한 이해도 부족
vector<string> split(string input,char del){
    vector<string> res;
    stringstream mystream(input);
    string splitdata;

    while(getline(mystream,splitdata,del)){
        res.push_back(splitdata);
    }
    return res;
}

int isSum(string input){
    int sum=0;
    vector<string>v=split(input,'+');
    for(int i=0;i<v.size();i++){
        sum+=stoi(v[i]);
    }

    return sum;
}