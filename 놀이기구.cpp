#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAX 10001
using namespace std;

int sch[MAX], check[MAX];
int time=0;
int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, i=0, cnt=6;
	cin >> n >> m;
	
	for(int i=1 ; i<= m ; i++){
		scanf("%d", &sch[i]);
	}
	if(n <= 5){
		cout << n ; exit(1);
	}
	
	while(1){
		time++; 
		for( i=1 ; i<=m ; i++){
			if(cnt >= n && time% sch[i]==0) { cout<< i ; exit(1); }
			
			else if(time % sch[i] ==0){
				cnt++;
			}
		}
	}
	return 0;
}
