#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N;
    int sum=0;
    cin >> N;
    string instr;
    cin >> instr;

    vector<int> v1;
    for(int i=0;i<N;i++){
        v1.push_back(instr[i]-'0');
    }
    vector<int>::iterator iter = v1.begin();
    while(iter!=v1.end()){
        sum+=*iter;
        iter++;
    }
    cout << sum << endl;




}