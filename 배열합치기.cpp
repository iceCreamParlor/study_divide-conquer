#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX 10000001
using namespace std;

int a[MAX], b[MAX], result[MAX];
int main(){
	freopen("input.txt", "r", stdin);
	int asize, bsize;
	cin >> asize >> bsize;
	for( int i=0 ; i< asize ; i++ )
		scanf("%d", &a[i]);
	for( int i=0 ; i< bsize ; i++ )
		scanf("%d", &b[i]);

	sort(&a[0], &a[asize-1]);
	sort(&b[0], &b[bsize-1]);
	int acnt=0 ; int bcnt=0 ; int resultcnt=0;
	while( acnt< asize && bcnt< bsize ){
		if(a[acnt] < b[bcnt]){
			result[resultcnt] = a[acnt]; acnt++; resultcnt++;
		}
		else{
			result[resultcnt] = b[bcnt]; bcnt++; resultcnt++;
		}
	}
	while( acnt< asize ){
		result[resultcnt] = a[acnt]; acnt++; resultcnt++;
	}
	while( bcnt< bsize ){
		result[resultcnt] = b[bcnt]; bcnt++; resultcnt++;
	}
	for( int i=0; i< resultcnt ; i++ )
		cout << result[i]<< " ";
	return 0;
}	