#include<stdio.h>
#include<math.h>

typedef struct point{
    float x;
    float y;
}p;

typedef struct visited{
    p p1;
    p p2;
}v;

int samepoint(p p1,p p2){
    if(p1.x == p2.x && p1.y == p2.y)
        return 1;
    else
        return 0;
}

int visitedindex=0;
int checkvisit(v *varr,p p1,p p2){
    for(int i=0;i<visitedindex;i++){
        if(samepoint(varr[i].p1,p1) && samepoint(varr[i].p2,p2)){
            //printf("check : truea\n");
            return 1;
        }            
        else if(samepoint(varr[i].p1,p2) && samepoint(varr[i].p2,p1)){
            //printf("check :trueb\n");
            return 1;
        }
    }
    if(visitedindex){
        //printf("check :false\n");
        return 0;
    }
    //printf("check : initial\n");
    return 0;
}

void addvisitedpoint(v *varr,p p1,p p2){
    varr[visitedindex].p1.x = p1.x;
    varr[visitedindex].p1.y = p1.y;
    varr[visitedindex].p2.x = p2.x;
    varr[visitedindex].p2.y = p2.y;
    visitedindex+=1;
}
void distance(p *pointarray, int n){
    float min=9999;
    float tmp;
    float result=0;
    v visitedarr[n-1];
    int flag=0;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
            if(i!=j){
                tmp = sqrt(pow(pointarray[i].x-pointarray[j].x,2)+pow(pointarray[i].y-pointarray[j].y,2));
                if(min>=tmp){
                    min=tmp;
                    flag=j;
                }
            }
        }
        //printf("min %f, index %d,flag %d\n",min,visitedindex,flag);
        if(!checkvisit(visitedarr, pointarray[i],pointarray[flag])){
            addvisitedpoint(&visitedarr[visitedindex],pointarray[i],pointarray[flag]);
            result+=min;
        }
        min=9999;
    }
    
    printf("%f",result);
}

int main(){
    int n;
    scanf("%d",&n);
    p parr1[n];
    for(int i=0;i<n;i++){
        scanf("%f %f",&parr1[i].x,&parr1[i].y);
    }

    distance(parr1, n);
}