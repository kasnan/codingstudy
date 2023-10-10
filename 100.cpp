#include<iostream>

using namespace std;

typedef struct Point{
    long x,y;
}Point;

Point P[10001];
int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> P[i].x >> P[i].y;
    }

    double res=0;
    P[N].x=P[0].x;
    P[N].y=P[0].y;

    for(int i=0;i<N;i++){
        res+=(P[i].x*P[i+1].y)-(P[i+1].x*P[i].y);
    }
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << abs(res)/2.0;

}
