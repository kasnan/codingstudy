#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int N;
    vector<int> v1;
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    sort(v1.begin(),v1.end());

    int K,start,end;
    int count=0;

    for(int i=0;i<N;i++){
        K=v1[i];
        start = 0;
        end = N-1;

        while(start!=end){
            if(v1[start]+v1[end]==K){
                count++;
                break;            
            }
            else if(v1[start]+v1[end]>K){
                end--;
            }
            else if(v1[start]+v1[end]<K){
                start++;
            }
            
        }
    }

    cout << count << endl;
}