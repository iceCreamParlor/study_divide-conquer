#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAX 10001

using namespace std;
typedef long long ll;
ll sch[MAX];
ll n, m, mid, cnt=6;

ll compute(ll time){
	ll result=0;
	for(int i=1 ; i<= m ; i++){
		result += (time / sch[i]);
	}
	return result;
}
int main()
{
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	for(int i=1 ; i<= m ; i++)
		scanf("%d", &sch[i]);
	if(n <= 5)	{cout << n ; exit(1);} 
	
	ll left =1, right = 2000000001;
	ll mini= MAX;
	while(left <= right){
		mid = (left + right)/2;
		if(compute(mid) <= n){
			left = mid +1;
			if(mini > mid) mini = mid; 
		}
		else if(compute(mid) > n){
			right = mid -1;
		}
		
	}
	cout << mid;
	return 0;
}
