#include<stdio.h>
#define MIN(x,y) (x>y ? y:x)
int main(){
    int x,y,w,h;
    scanf("%d %d %d %d",&x,&y,&w,&h);
    int min1=MIN(MIN(w-x,x),MIN(h-y,y));
    printf("%d",min1);
}