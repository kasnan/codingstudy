#include<iostream>
using namespace std;

typedef struct Point{
    int x,y;
}Point;

Point P[4];

int main(){
    for(int i=1;i<4;i++){
        cin >> P[i].x >> P[i].y;
    }

    int ccw = P[1].x*P[2].y+P[2].x*P[3].y+P[3].x*P[1].y;
    ccw-= P[2].x*P[1].y+P[3].x*P[2].y+P[1].x*P[3].y;
    int ans=0;
    if(ccw>0){
        ans=1;
    }
    else if(ccw<0){
        ans=-1;
    }

    cout << ans;
}