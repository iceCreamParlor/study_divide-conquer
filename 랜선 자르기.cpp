#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

long long lan[MAX]; long long result;
int main()
{
	freopen("input.txt", "r", stdin);
	long long num, many;
	scanf("%lld %lld", &num, &many);

	for(long long i=0 ; i< num ; i++){
		scanf("%lld", &lan[i]);
	}
	sort(&lan[0], &lan[num]);
	
	long long left = 1, right = lan[num-1];long long temp=0; long long mid;
	while( left <= right ){
		mid = (left + right)/2;
		temp=0;
		for( long long i=0  ; i< num ; i++){
			temp += lan[i]/ mid;
		}
		if( temp >= many ) {
			left =  mid + 1;
			if(mid > result) result = mid;
		}
		else if( temp < many ) right = mid- 1;
		
	}
	printf("%lld", result);
	return 0;
}
