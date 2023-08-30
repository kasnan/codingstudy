#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> vec1;

int main(){
    int N,tmp;
    cin >> N;
    // c style
    // int i=0;
    // while(i<N){
    //     cin >> tmp;
    //     vec1.push_back(tmp);
    //     i++;
    // }
    // sort(vec1.begin(),vec1.end());
    // i=0;
    // while(i<N){
    //     cout << vec1[i] << endl;
    //     i++;
    // }
    
    vector<int>::iterator iter;
    int count=0;
    while(count<N){
        cin >> tmp;
        vec1.push_back(tmp);
        count++;
    }

    sort(vec1.begin(),vec1.end());
    for(iter=vec1.begin();iter!=vec1.end();iter++)
        cout << *iter << endl;


}