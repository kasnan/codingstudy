#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    //1부터 N까지 나란히 배치된 배열을 생각
    int start,end;
    start = end = 1;

    int sum = 1;
    int count = 1;

    while(end != N){
        if(sum == N){
            count++;
            end++;
            sum+=end;
        }
        else if(sum > N){
            sum-=start;
            start++;
        }
        else{
            end++;
            sum+=end;
        }
    }

    cout << count << endl;
}