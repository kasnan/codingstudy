#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<float> v1;
    float tmp, max=-1;
    float sum=0;

    for(int i=0;i<N;i++){
        cin >> tmp;
        if(tmp > max){
            max = tmp;
        }
        v1.push_back(tmp);
    }

    for(int i=0;i<N;i++){
        v1[i] = (v1[i]/max)*100;
        sum+=v1[i];
    }
    sum/=N;
    cout << sum << endl;
}