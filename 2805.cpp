#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAX 1000001
using namespace std;
long long  tree[MAX];
int main()
{
	freopen("input.txt", "r", stdin);
	long long num, length, mid; long long result=0;
	scanf("%lld %lld", &num, &length);
	for(int i=0 ; i< num ; i++){
		scanf("%lld", &tree[i]);
	}
	sort(&tree[0], &tree[num]);
	long long left =0, right= tree[num-1];
	while(left <= right){
		long long leftover=0; 
		mid = ( left + right )/2;
		for(long long i=0 ; i< num ; i++){
			if(tree[i] > mid)
				leftover+= tree[i] - mid;
		}
		
		if(leftover >= length){
			result = max(result, mid);
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	cout << result;
	return 0;
}
