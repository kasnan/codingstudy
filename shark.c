#include<stdio.h>
#include<stdlib.h>
#define ABS(x) ( ((x)<0)?-(x):(x) )


int main(){
    int n;
    int r,c;
    int size=2;
    int i,j;
    scanf("%d",&n);
    int space[n][n];
    int fishcnt=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&space[i][j]);
            if(space[i][j]==9){
                r=i;
                c=j;
            }
            else if(space[i][j]>0){
                fishcnt++;
            }
        }
    }
    int dist=0;
    int find_equal=0;
    int minr=9999,minc=9999;
    int flag=0;
    // printf("%d\n",fishcnt);
    if(fishcnt==0){
        printf("0\n");
    }
    
    else{
        while(fishcnt>0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(space[i][j]>0 && space[i][j]<size){

                        if((ABS(r-minr)+ABS(c-minc)>ABS(r-i)+ABS(c-j))){
                            minr=i;
                            minc=j;                            
                        }
                        else if((ABS(r-minr)+ABS(c-minc)==ABS(r-i)+ABS(c-j))){
                            if(minr>=i && minc>=j){
                                minr=i;
                                minc=j;
                            }
                        }
                    }
                    
                    else if(space[i][j]==size && find_equal ==1){
                        if((ABS(r-minr)+ABS(c-minc)>=ABS(r-i)+ABS(c-j))){
                            minr=i;
                            minc=j;                            
                        }
                    }
                    
                }
                
            }

            if(minr != 9999 && minc != 9999 && find_equal==0){
                dist+=ABS(r-minr)+ABS(c-minc);
                printf("%d%d dist: %d\n",minr,minc,dist);
                
                
                r=minr;
                c=minc;
                space[minr][minc]=-1;
                fishcnt--;
                flag++;

                if(size == flag){
                    flag=0;
                    size++;
                }

                minr=minc=9999;
            }
            else if(find_equal==1){
                if(minr!=9999 && minc!=9999){
                    dist+=ABS(r-minr)+ABS(c-minc);
                    r=minr;
                    c=minc;
                    find_equal=0;
                }
                else
                    break;
            }
            else{
                find_equal=1;
            }
        }
    }
    printf("%d",dist);
    return 0;
}
// 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
// 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
// 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
// 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
// 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
 
//가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.
//아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

// 0: 빈 칸
// 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
// 9: 아기 상어의 위치