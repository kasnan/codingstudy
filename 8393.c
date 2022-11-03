#include<stdio.h>

int stacksum(int n){
    if(n==1)
        return 1;
    return n+stacksum(n-1);
}

int main(){
    int n;
    scanf("%d",&n);

    printf("%d",stacksum(n));
}