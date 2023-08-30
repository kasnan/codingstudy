#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    // 선언
    vector<int> vec1;
    vector<int>::iterator iter;

    // 삽입
    vec1.push_back(1); //뒤에 삽입
    vec1.insert(vec1.begin(),21); //첫번째 패러미터에 해당하는 위치에 삽입

    vec1.push_back(3);
    vec1.push_back(3);
    vec1.push_back(3);
    vec1.push_back(3);

    // 값 변경
    vec1[0]=5;

    // 삭제
    vec1.pop_back();
    vec1.erase(vec1.begin()+1);
    // vec1.clear();

    // 정보 가져오기
    vec1.size();
    vec1.front();
    vec1.back();
    vec1[0];
    vec1.at(3);
    vec1.begin();
    vec1.end();
    
    iter=vec1.begin();
    while(iter!=vec1.end()){
        cout << *iter << endl;
        iter++;
    }



}    