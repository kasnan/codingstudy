#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,temp_0,temp_2;
    cin >> n;
    int A[3];
    int minD[3],maxD[3];
    for(int j=0;j<3;j++){
        cin >> minD[j];
        maxD[j]=minD[j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> A[j];
        }
        temp_0 = maxD[0]; temp_2 = maxD[2];
        maxD[0] = max(maxD[0], maxD[1]) + A[0];
        maxD[2] = max(maxD[1], maxD[2]) + A[2];
        maxD[1] = max(max(temp_0, maxD[1]), temp_2) + A[1];

        temp_0 = minD[0]; temp_2 = minD[2];
        minD[0] = min(minD[0], minD[1]) + A[0];
        minD[2] = min(minD[1], minD[2]) + A[2];
        minD[1] = min(min(temp_0, minD[1]), temp_2) + A[1];
    }

    cout << max(max(maxD[0],maxD[1]),maxD[2]) << " ";
    cout << min(min(minD[0],minD[1]),minD[2]);
}