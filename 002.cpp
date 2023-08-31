#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<float> v1;
    float tmp;
    float sum=0;

    for(int i=0;i<N;i++){
        cin >> tmp;
        v1.push_back(tmp);
    }

    tmp = v1.front();
    for(int i=0;i<N;i++){
        if(v1[i]>tmp)
            tmp=v1[i];
    }

    for(int i=0;i<N;i++){
        v1[i] = (v1[i]/tmp)*100;
        sum+=v1[i];
    }
    sum/=N;
    cout << sum << endl;
}