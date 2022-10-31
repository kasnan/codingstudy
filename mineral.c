#include<stdio.h>

int left[2]={0,};
int right[2]={0, };

void printCAVE(char **cave,int r,int c){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("%c ",cave[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int r,c;
    int n;
    int i;
    printf("r,c input\n");
    scanf("%d %d",&r,&c);
    char cave[r+1][c+1];
    printf("cave input\n");
    for(i=1;i<=r;i++){
            scanf("%s",&cave[i]);
    }

    printf("n input >> ");
    scanf("%d",&n);
    int h[100]={0, };
    printf("h input\n");
    for(i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    
    i=0;
    
    while(h[i]){
        
        for(int j=1;j<=c;j++){
            left[0] = r-h[i]; left[1]=j;
            right[0] = r-h[i]; right[1]=j;

            if(cave[left[0]][left[1]] == 'X'){
                cave[left[0]][left[1]] == '.';
                if(cave[left[0]-1][left[1]]== 'X'){
                    char tmp;
                    tmp = cave[left[0]-1][left[1]];
                    cave[left[0]-1][left[1]] = cave[left[0]][left[1]];
                    cave[left[0]][left[1]] = tmp;
                }
            }
            
            if(cave[right[0]][right[1]] == 'X'){
                cave[right[0]][right[1]] == '.';
                if(cave[right[0]-1][right[1]]== 'X'){
                    char tmp;
                    tmp = cave[right[0]-1][right[1]];
                    cave[right[0]-1][right[1]] = cave[right[0]][right[1]];
                    cave[right[0]][right[1]] = tmp;
                }
            }

        }
        i++;
    }

    printCAVE(cave,r,c);

}
//2933번 나중에 다시 풀기