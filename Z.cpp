#include <stdio.h>
#include <iostream>
using namespace std;

int compute(int row){
	int i;
	for( i=0; i< row; i+=2);
	return i-2;
}
int compute2(int col){
	int i;
	for( i=0; i< col; i+=2);
	return i-2;
}
int length(int size){
	int temp=1;
	for(int i=1 ; i<= size; i++){
		temp *= 2;
	}
	return temp;
}
int main()
{
	freopen("input.txt", "r", stdin);
	
	int size, row, col;
		while(scanf("%d %d %d",&size, &row, &col) != EOF){
		int result=0;
		row++; col++;

		if(size==1) cout << 2*(row-1)+(col-1)<< endl;
		else{
			int div = compute(row); int div2 = compute2(col);
			result += div* length(size);
			result += div2* length(size);
			result -= div*div2;
			row -= compute(row)+1;
			col -= compute(col)+1;
			result += row*2+ col;
			cout << result;
		}
	}
	return 0;
}
