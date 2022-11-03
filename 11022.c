#include<stdio.h>

void printTest(int testnum){
    int A,B;
    char *pref="Case #";
    scanf("%d %d",&A,&B);
    printf("%s%d: %d + %d = %d\n",pref,testnum+1,A,B,A+B);
}

int main(){
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
        printTest(i);
}