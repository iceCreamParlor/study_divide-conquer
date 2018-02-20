#include <cstdio>
#include <iostream>
#define MAX 2200
using namespace std;
int mat[MAX][MAX];
int result[5];

bool same(int row, int col, int num){
	int temp = mat[row][col]; bool check=true;
	for( int i=row ; i< row+num; i++ ){
		if(!check) break;
		for( int j=col ; j< col+num; j++ ){
			if( temp != mat[i][j] ){
				check=false; break;
			}
		}
	}
	return check;
}
void compute(int row, int col, int num){
	if(num==1){
		result[ mat[row][col]+1 ]++; return;
	}
	else if( same(row, col, num) ){
		result[ mat[row][col]+1 ]++; return;
	}
	else{
		int m= num/3;
		for( int i=0; i< 3 ;i++ ){
			for( int j=0 ; j<3 ; j++ ){
					compute(row + i*m, col+ j*m, m);
			}
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	int num;
	cin >> num;
	for(int i=0 ; i< num ; i++){
		for(int j=0 ; j< num ; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	compute(0,0,num);
	printf("%d\n%d\n%d", result[0], result[1], result[2]);
	return 0;
}