#include <cstdio>
// DP와 이분 탐색 모두 이용한다.
using namespace std;
int n; int dp[22];
void solve(int n, int x, int y){
	if(n==0 ) return;
	solve(n-1, x, 6-x-y);
	printf("%d %d\n", x, y);
	solve(n-1, 6-x-y, y);
}
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	dp[1] = 1;
	for(int i=2; i<= n; i++){
		dp[i] = 2*dp[i-1] +1; // n-1 개를 2만큼 옮기고(n), 맨 아래판을 3으로 옮기고 (1), 2에 있던 것을 다시 3으로 옮긴다(n)
	}
	printf("%d\n", dp[n]);
	solve(n, 1, 3);
	return 0;
}