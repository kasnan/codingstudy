#include<stdio.h>
#define MIN(x,y) (x>y ? y:x)
#define MAX(x,y) (x>y ? x:y)

int check(int *arr){
    for(int i=0;i<3;i++){
        if(arr[i] == arr[3])
            return i;
    }
}

int main(){
    int N;
    scanf("%d",&N);
    int costarr[N+1][4];
    int result=0;
    for(int i=1;i<=N;i++){
        scanf("%d %d %d",&costarr[i][0],&costarr[i][1],&costarr[i][2]);
    }
    costarr[1][3] = MIN(costarr[1][0],MIN(costarr[1][1],costarr[1][2]));
    int beforeindex=check(costarr[1]);

    result+=costarr[1][3];
    for(int i=2;i<=N;i++){
        costarr[i][3]=MAX(costarr[i][0],MAX(costarr[i][1],costarr[i][2]));
        for(int j=0;j<3;j++){
            if(costarr[i][j]<costarr[i][3]){
                if(j!=beforeindex)
                    costarr[i][3]=costarr[i][j];
                else
                    continue;
            }
                
        }
        beforeindex=check(costarr[i]);
        result+=costarr[i][3];
    }
    printf("%d",result);
    
}