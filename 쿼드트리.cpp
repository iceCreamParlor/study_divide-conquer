#include <cstdio>
#include <iostream>
#define MAX 66
int num, map[MAX][MAX];
using namespace std;

bool same(int row, int col, int size){
	int temp = map[row][col];
	for(int i=0 ; i< size; i++){
		for(int j=0 ; j< size; j++){
			if(map[row+i][col+j] != temp) 
				return false;
		}
	}
	return true;
}
void compute(int row, int col, int num){
	
	if(num==1) cout << map[row][col];
	else{
		
		if(same(row, col, num)){
			cout<<map[row][col];
		}
		else{
			cout << '(';
			int newnum = num/2;
			for(int i= 0; i<2 ; i++){
				for(int j=0 ; j<2 ; j++){
					compute(row+i*newnum, col+j*newnum, newnum);
				}
			}		
			cout << ')';
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	cin >> num; 
	for(int i=0 ; i< num ; i++){
		for(int j=0 ; j< num ; j++){
			scanf("%1d", &map[i][j]); 
		}
	}
	compute(0,0,num);
	return 0;
}