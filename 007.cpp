#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N;
    cin >> M;

    vector<int> v1;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }

    sort(v1.begin(),v1.end());
    int sum;
    int count=0;

    int start=0;
    int end=N-1;
    while(end>start){
        sum=v1[start]+v1[end];
        if(sum>M){
            end--;
        }
        else if(sum<M){
            start++;
        }
        else{
            count++;
            start++;
            end--;        
        }
    }

    cout << count << endl;


}