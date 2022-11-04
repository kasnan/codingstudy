#include<stdio.h>
#define MIN(x,y) (x>y ? y:x)
int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int tmp=1, gcd;
    while(tmp<=MIN(n1,n2)){
        if(n1%tmp == 0 && n2%tmp==0)
            gcd=tmp;
        tmp++;
    }
    int lcm;
    lcm=n2/gcd*n1;

    printf("%d\n",gcd);
    printf("%d\n",lcm);


}