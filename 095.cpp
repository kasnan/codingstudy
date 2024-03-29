#include<iostream>
#include<climits>


using namespace std;

static int INF = 1000000 * 16 + 1;

int D[16][1 << 16];
int N;
int W[16][16];

int tsp(int c,int v);

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> W[i][j];
        }
    }

    cout << tsp(0,1) << endl;

}

int tsp(int c,int v){
    if(v==(1<<N)-1){
        return W[c][0] ==0 ? INF : W[c][0];
    }

    if(D[c][v]!=0){
        return D[c][v];
    }

    int min_val=INF;
    for(int i=0;i<N;i++){
        if((v & (1<<i)) == 0 && W[c][i]!=0){
            min_val=min(min_val,tsp(i,(v|(1<<i)))+W[c][i]);
        }
    }
    
    D[c][v]=min_val;
    return D[c][v];
}