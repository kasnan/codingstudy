#include<iostream>

#define INF 987654321

using namespace std;

long D[101][101];

int main(){
    int n,m;
    cin >> n >> m;

    //거리 행렬 초기화
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i==j){
                D[i][j]=0;
            }
            else{
                D[i][j]=INF;
            }
        }
    }

    // edge 정보 입력받아 현재 값과 비교 후,
    // 더 작은 값으로 거리 행렬 값 수정
    for(int i=0;i<m;i++){
        long a,b,c;
        cin >> a >> b >> c;
        D[a][b]=min(D[a][b],c);
    }

    // 플로이드-워셜 점화식
    // 모든 노드에서 모든 노드로 가는 거리에 대해
    // 가능한 모든 중간 경유지를 거쳐서 최소의 거리를 찾을 수 있도록
    for(int k=1;k<n+1;k++){
        for(int s=1;s<n+1;s++){
            for(int e=1;e<n+1;e++){
                D[s][e]=min(D[s][e],D[s][k]+D[k][e]);
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(D[i][j]==INF){
                cout << 0 << " ";
            }
            else{
                cout << D[i][j] << " ";
            }
            
        }
        cout << "\n";
    }
    
    
    
}