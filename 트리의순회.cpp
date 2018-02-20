#include <stdio.h>
#include <iostream>
using namespace std;
int num;
struct node
{
	char  left, right;
};
node arr[100];

void preorder(char root){
	if(root=='.') return;
	else{
		cout << root;
		preorder(arr[root].left);
		preorder(arr[root].right);
	}
}
void inorder(char root){
	if(root=='.') return;
	else{
		inorder(arr[root].left);
		cout << root;
		inorder(arr[root].right);
	}
}
void postorder(char root){
	if(root=='.') return;
	else{
		postorder(arr[root].left);
		postorder(arr[root].right);
		cout << root;
	}
}
int main(int argc, char *argv[])
{
	freopen("input.txt", "r",stdin);
	cout << arr[1].left << endl;
	cin >> num;
	for(int i=0; i< num ; i++){
		char root, rtemp, ltemp;
		cin >> root >> ltemp >> rtemp;
		arr[root].left = ltemp;
		arr[root].right = rtemp;
	}
	preorder('A'); cout << endl;
	inorder('A'); cout << endl;
	postorder('A'); cout << endl;
	return 0;
}
