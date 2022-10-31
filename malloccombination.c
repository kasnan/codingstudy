#include<stdio.h>
#include<stdlib.h>//malloc함수를 사용하기 위함

int *arr;
int *copy;//나열할 배열
void Combination(int *arr, int *copy, int n, int r, int depth);
void print_arr(int *copy, int n);

int main(){
	int n,r,c;
	
	//n과 r을 공백을 두고 입력받는다
	scanf("%d %d",&n,&r);
	c=r;
	//n개 중에서 n개의 배열 할당
	arr = (int*)malloc(n*sizeof(int));
	//r개를 선택한것을 담기위한 배열
	copy = (int*)malloc(r*sizeof(int));

	//n배열 값 입력
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	
	Combination(arr,copy,n,r,c);
	
	free(arr);
	free(copy); //동적 할당 해제
	return 0;
}
void print_arr(int *copy, int n){
	for(int i =0;i<n;i++){
		printf("%d",copy[i]);
	}
	printf("\n");
}
void Combination(int *arr, int *copy, int n, int r, int depth){
	if(r==0){
		print_arr(copy, depth);
		return;
	}	
	if(n<r){
		return;
	}else{
		copy[r-1] = arr[n-1];
		Combination(arr,copy,n-1,r-1,depth);
		Combination(arr,copy,n-1,r,depth);
	}
}