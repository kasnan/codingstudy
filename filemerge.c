#include<stdio.h>
#include<stdlib.h>

typedef struct testdata
{
    int chapter;
    int *filesize;
}TD;

void test(TD test){
    int cost=0;
    int size=sizeof(test.filesize)/sizeof(int);
    



    printf("%d\n",cost);
}

void computemincost(TD *test,int testcase){
    for(int i=0;i<testcase;i++){
        eachtest(test[i]);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    TD test[T];
    for(int i=0;i<T;i++){
        scanf("%d",&test[i].chapter);
        test[i].filesize = (int *)malloc(sizeof(int)*test[i].chapter);
        for(int j=0;j<test[i].chapter;j++){
            scanf("%d",&test[i].filesize[j]);
        }
    }
    
    computemincost(test, T);
    free(test);
}