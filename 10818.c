#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int tmp,min=1000000,max=-1000000;
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        if(min>tmp)
            min=tmp;
        if(max<tmp)
            max=tmp;
    }
    printf("%d %d",min,max);

}