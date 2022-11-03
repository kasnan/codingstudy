#include<stdio.h>

int main(){
    int X;
    scanf("%d",&X);
    int N;
    scanf("%d",&N);
    int a[N],b[N];
    int sum=0;
    for(int i=0;i<N;i++){
        scanf("%d %d",&a[i],&b[i]);
        sum+=a[i]*b[i];
    }
    if(sum == X)
        printf("Yes");
    else
        printf("No");

}