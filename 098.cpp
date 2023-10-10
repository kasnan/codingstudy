#include<iostream>
using namespace std;

typedef struct Point{
    long x,y;

}Point;

Point P[4];

int ccwF(long p1,long p2,long p3){
    long ccw = P[p1].x*P[p2].y+P[p2].x*P[p3].y+P[p3].x*P[p1].y;
    ccw-= P[p2].x*P[p1].y+P[p3].x*P[p2].y+P[p1].x*P[p3].y;

    if(ccw>0){
        return 1;
    }
    else if(ccw<0){
        return -1;
    }
    return 0;
}

bool isOverlab(){
    if(min(P[0].x,P[1].x)<=max(P[2].x,P[3].x) &&
        min(P[2].x,P[3].x)<=max(P[0].x,P[1].x) &&
        min(P[0].y,P[1].y)<=max(P[2].y,P[3].y) &&
        min(P[2].y,P[3].y)<=max(P[0].y,P[1].y)){
            return true;
        }
    return false;
}

bool isCross(){
    int abc = ccwF(0,1,2);
    int abd = ccwF(0,1,3);
    int cda = ccwF(2,3,0);
    int cdb = ccwF(2,3,1);

    if(abc*abd==0 && cda*cdb==0){
        return isOverlab();
    }
    else if(abc*abd<=0 && cda*cdb<=0){
        return true;
    }
    return false;
}

int main(){
    for(int i=0;i<4;i++){
        cin >> P[i].x >> P[i].y;
    }
    bool res=isCross();
    int ans=0;
    if(res){
        ans=1;
    }

    cout << ans;
}