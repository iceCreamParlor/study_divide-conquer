#include <stdio.h>
#include <iostream>
#define MAX 100001
using namespace std;
int inorder[MAX], postorder[MAX], check[MAX];
int num, save;

void compute(int lastp){
	if(check[lastp]==1) return;
	cout << lastp << " ";
	for(int i=0 ; i< num ; i++){
		if(inorder[i] == lastp && i>0 && check[lastp]==0){
			check[lastp]=1;
			compute( inorder[i-1] );
		}
		else if(inorder[i] == lastp && i==0 && check[lastp]==0){
			check[lastp]=1;			
			compute( postorder[num-2] );
		}
	}
}
int main(int argc, char *argv[])
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(int i=0 ; i< num ; i++){
		scanf("%d", &inorder[i]);	
	}
	for(int i=0 ; i< num ; i++){
		scanf("%d", &postorder[i]);
	}
	/*
	for(int i=0 ; i< num ; i++){
		if(inorder[i] == postorder[num-1])
			save = i+1;
	}*/
	compute(postorder[num-1]);
	return 0;
}
