#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    char inch;
    int sum=0;
    for(int i=0;i<N;i++){
        scanf("%c",&inch);
        sum+=inch-48;
    }
    printf("%d\n",sum);
}