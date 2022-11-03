#include<stdio.h>

int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int tmp;
    tmp=n1*(n2%10);
    printf("%d\n",tmp);
    tmp=n1*((n2%100)-(n2%10))/10;
    printf("%d\n",tmp);
    tmp=(n2-(n2%100))/100*n1;
    printf("%d\n",tmp);
    printf("%d\n",n1*n2);
    
}