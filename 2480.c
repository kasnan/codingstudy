#include<stdio.h>
#define MAX(x,y) (x>y ? x:y)
int max(int n1,int n2,int n3){
    return MAX(MAX(n1,n2),n3);
}

int main(){
    int n1,n2,n3;
    scanf("%d %d %d",&n1,&n2,&n3);

    if(n1==n2 && n2==n3)
        printf("%d",10000+n1*1000);
    else if(n1==n2 || n1==n3 || n2==n3){
        if(n1==n2)
            printf("%d",1000+n1*100);
        else if(n1==n3)
            printf("%d",1000+n1*100);
        else
            printf("%d",1000+n2*100);
    }
    else
        printf("%d",max(n1,n2,n3)*100);
}